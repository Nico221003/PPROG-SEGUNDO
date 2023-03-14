/** 
 * @brief It implements the game interface and all the associated calls
 * for each command
 * 
 * @file game.c
 * @author Profesores PPROG
 * @version 3.0 
 * @date 26-01-2023 
 * @copyright GNU Public License
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "game.h"

/**
   Private functions
*/  
STATUS game_command_unknown(Game *game);
STATUS game_command_exit(Game *game);
STATUS game_command_next(Game *game);
STATUS game_command_back(Game *game);
STATUS game_command_take(Game *game);
STATUS game_command_drop(Game *game);
STATUS game_command_left(Game *game);
STATUS game_command_right(Game *game);
STATUS game_command_attack(Game *game);

/**
   Game interface implementation
*/

STATUS game_create(Game *game){

  int i;

  for(i = 0; i < MAX_SPACES; i++) {
    game->spaces[i] = NULL;
  }

  for(i = 0; i < MAX_OBJ; i++){
    game->object[i] = NULL;
  }
  
  game->player = player_create(PLAYER_ID);
  game_set_player_location(game, 11);

  game->enemy = enemy_create(ENEMY_ID);
  game_set_enemy_location(game, 121);

  /*game->object = object_create(11); AHORA HAY MÁS DE 1 OBJETO => READFROMFILE*/

  /*game->player_location = NO_ID;
  game->object_location = NO_ID;*/

  /*game_set_player_location(game, NO_ID);*/
  /*player_set_location(game->player, NO_ID);*/
  /*game_set_object_location(game, 121);*/

  game->last_cmd = NO_CMD;

  return OK;
}


STATUS game_destroy(Game *game) {
  int i = 0;

  for (i = 0; i < MAX_SPACES && game->spaces[i] != NULL; i++) {
    space_destroy(game->spaces[i]);
  }

  for(i=0; i<MAX_OBJ && game->object[i] != NULL; i++){
    object_destroy(game->object[i]);
  }

  player_destroy(game->player);

  enemy_destroy(game->enemy);

  return OK;
}


char *game_get_object_name(Game *game, Id idobj){

  int i=0;

  if(game == NULL || idobj == NO_ID){
    return ERROR;
  }

  /*Buscamos el object que queremos dentro del array de objetos*/
  for(i=0; i<MAX_OBJ && game->object[i]; i++){
    if(idobj == object_get_id(game->object[i])){
      break;
    }
  }

  return object_get_name(game->object[i]);
}



Space *game_get_space(Game *game, Id id){
  int i = 0;

  if (id == NO_ID) {
    return NULL;
  }

  for (i = 0; i < MAX_SPACES && game->spaces[i] != NULL; i++) {
    if (id == space_get_id(game->spaces[i])) {
      return game->spaces[i];
    }
  }

  return NULL;
}


STATUS game_set_player_location(Game *game, Id id){

  if (id == NO_ID) {
    return ERROR;
  }

  /*game->player_location = id;*/

  player_set_location(game->player, id);

  return OK;
}

Id game_get_player_location(Game *game) {

  if(!game){
    return NO_ID;
  }

  /*return game->player_location;*/

  return player_get_location(game->player);
}


Id game_get_enemy_location(Game *game){

  if(!game){
    return NO_ID;
  }

  /*return game->player_location;*/

  return enemy_get_location(game->enemy);
}


STATUS game_set_enemy_location(Game *game, Id id){

  if(game == NULL || id == NO_ID){
    return ERROR;
  }

  enemy_set_location(game->enemy, id);

  return OK;
}


STATUS game_set_object_location(Game *game, Id id, Id idobj){

  int i=0;

  if (id == NO_ID || idobj == NO_ID){
    return ERROR;
  }

  for(i=0; game->spaces[i] != NULL; i++){

    if(space_get_id(game->spaces[i]) == id){

      space_set_object(game->spaces[i], idobj);
      return OK;
    }

  }

  /*game->object_location = id;
  aux = space_set_object(game_get_space(game, id), TRUE);

  if(aux == ERROR){
    return ERROR;
  }*/

  return ERROR;
}

/*Gets the location of an object of the game => returns id of the space where it is*/
Id game_get_object_location(Game *game, Id idobj){

  int i;

  if (idobj == NO_ID)
  {
    return NO_ID;
  }

  for (i = 0; game->spaces[i] != NULL && i < MAX_SPACES; i++){

    if (space_get_object(game->spaces[i], idobj) == TRUE)
    {
      return space_get_id(game->spaces[i]);
    }
  }

  return NO_ID;
}


Id game_get_object_id(Game *game, int num_obj){
  
  if(game == NULL){
    return NO_ID;
  }

  return object_get_id(game->object[num_obj]);
}


int game_get_enemy_health(Game *game){

  if (!game)
  {
    return -1;
  }

  /*return game->player_health;*/

  return enemy_get_health(game->enemy);
}


STATUS game_set_enemy_health(Game *game, int health){

  if(!game){
    return ERROR;
  }

  return enemy_set_health(game->enemy, health);
}


int game_get_player_health(Game *game){

  if (!game)
  {
    return NO_ID;
  }

  /*return game->player_health;*/

  return player_get_health(game->player);
}


STATUS game_set_player_health(Game *game, int health){

  if(!game){
    return ERROR;
  }

  return player_set_health(game->player, health);
}


STATUS game_update(Game *game, T_Command cmd) {
  game->last_cmd = cmd;
  
  switch (cmd) {
    case UNKNOWN:
      game->state = game_command_unknown(game);
      break;

    case EXIT:
      game->state = game_command_exit(game);
      break;

    case NEXT:
      game->state = game_command_next(game);
      break;

    case BACK:
      game->state = game_command_back(game);
      break;

    case TAKE:
      game->state = game_command_take(game);
      break;
    
    case DROP:
      game->state = game_command_drop(game);
      break;

    case LEFT:
      game->state = game_command_left(game);
      break;
    
    case RIGHT:
      game->state = game_command_right(game);
      break;

    case ATTACK:
      game->state = game_command_attack(game);
      break;

    default:
      break;
  }

  return OK;
}

T_Command game_get_last_command(Game *game) {
  return game->last_cmd;
}

void game_print_data(Game *game) {

  int i=0, j=0;
  Id id_aux = NO_ID;
  Id id_loc = NO_ID;

  /*Spaces info*/
  printf("=> Spaces: \n");
  for (i = 0; i < MAX_SPACES && game->spaces[i] != NULL; i++) {
    space_print(game->spaces[i]);
  }

  /*Objects info*/
  printf("=> Objects: \n");

  for(i=0; i<MAX_OBJ && game->object[i] != NULL; i++){

    id_aux = object_get_id(game->object[i]);
    id_loc = game_get_object_location(game, id_aux);

    for(j=0; j<MAX_SPACES && game->spaces[j] != NULL; j++){

      if(id_loc == space_get_id(game->spaces[j])){
        printf("--> Objeto %ld -> located in %ld\n", id_aux, id_loc);
        break;
      }

    }

  }


  /*Player info*/
  printf("=> Player location: %d\n", (int)player_get_location(game->player));
}


/*States if the game is over*/
BOOL game_is_over(Game *game){

  if(game == NULL){
    printf("Hola");
    return TRUE;
  }

  if(game_get_player_health(game) == 0){
    return TRUE;
  }

  return FALSE;
}


/**
   Calls implementation for each action 
*/
STATUS game_command_unknown(Game *game){

  return ERROR;
}

STATUS game_command_exit(Game *game){

  return OK;
}

STATUS game_command_next(Game *game) {
  Id current_id = NO_ID;
  Id space_id = NO_ID;

  space_id = game_get_player_location(game);
  if (space_id == NO_ID) {
    return ERROR;
  }

  current_id = space_get_south(game_get_space(game, space_id));
  if (current_id != NO_ID) {
    game_set_player_location(game, current_id);
  }
  
  return OK;
}

STATUS game_command_back(Game *game) {
  Id current_id = NO_ID;
  Id space_id = NO_ID;

  space_id = game_get_player_location(game);

  if (NO_ID == space_id) {
    return ERROR;
  }

  current_id = space_get_north(game_get_space(game, space_id));
  if (current_id != NO_ID) {
    game_set_player_location(game, current_id);
  }
  
  return OK;
}

STATUS game_command_left(Game *game){
  Id current_id = NO_ID;
  Id space_id = NO_ID;

  space_id = game_get_player_location(game);
  if (space_id == NO_ID)
  {
    return ERROR;
  }

  current_id = space_get_west(game_get_space(game, space_id));
  if (current_id != NO_ID)
  {
    game_set_player_location(game, current_id);
  }

  return OK;
}

STATUS game_command_right(Game *game){
  Id current_id = NO_ID;
  Id space_id = NO_ID;

  space_id = game_get_player_location(game);
  if (space_id == NO_ID)
  {
    return ERROR;
  }

  current_id = space_get_east(game_get_space(game, space_id));
  if (current_id != NO_ID)
  {
    game_set_player_location(game, current_id);
  }

  return OK;
}


STATUS game_command_attack(Game *game){

  int num;
  Id player_hp = NO_ID;
  Id enemy_hp = NO_ID;
  Id player_id = NO_ID;
  Id enemy_id = NO_ID;

  if (!game)
  {
    return ERROR;
  }

  player_hp = game_get_player_health(game);
  enemy_hp = game_get_enemy_health(game);

  if (player_hp == 0 || enemy_hp == 0)
  {
    return ERROR;
  }

  player_id = game_get_player_location(game);
  if (player_id == NO_ID)
  {
    return ERROR;
  }

  enemy_id = game_get_enemy_location(game);
  if (enemy_id == NO_ID)
  {
    return ERROR;
  }

  if (player_id != enemy_id)
  {
    return ERROR;
  }

  /*obtenemos un número aleatorio*/
  srand(time(NULL));

  num = rand() % 10;

  if (num % 2 == 0)
  {
    game_set_enemy_health(game, enemy_hp - 1);
  }
  else if (num % 2 != 0)
  {
    game_set_player_health(game, player_hp - 1);
  }

  return OK;
}

STATUS game_command_take(Game *game){

  /*
  int i=0;

  Id object_id = NO_ID;
  Id playerloc_id = NO_ID;
  Id objectloc_id = NO_ID;

  if(!game){
    return;
  }

  Comprobar que player esté en el mismo hab que el objeto
  playerloc_id = game_get_player_location(game);
  objectloc_id = game_get_object_location(game);

  if(playerloc_id != objectloc_id){
    return;
  }

  Meter id de objeto en player->object y poner object->location a NO_ID
  object_id = object_get_id(game->object);

  for(i=0; i<MAX_SPACES; i++){

    if(space_get_id(game->spaces[i]) == game_get_object_location(game)){

      space_set_object(game->spaces[i], NO_ID);

    }

  }

  player_set_object(game->player, object_id);

  */

  int i=0, flag=0;
  Space *s = NULL;

  Id id_obj = NO_ID;
  char c;

  if(scanf(" o%ld",&id_obj) == 0){
    while((c = getchar()) != '\n');
    printf("error");
    return ERROR;
  }

  while((c = getchar()) != '\n');
  fprintf(stdout, "id_object = %ld", id_obj);
  for(i=0; i<MAX_OBJ; i++){
    if(object_get_id(game->object[i]) == id_obj){
      flag++;
    }
  }

  if(flag == 0){
    return ERROR;
  }
  if(game == NULL || id_obj == NO_ID){
    return ERROR;
  }

  if(space_get_object(game_get_space(game, game_get_player_location(game)), id_obj) == FALSE){
    return ERROR;
  }

  if((s = game_get_space(game, game_get_player_location(game))) == NULL){
    return ERROR;
  }

  if(player_get_object(game->player) != NO_ID){
    return ERROR;
  }

  if(space_get_object(s, id_obj)==TRUE && player_get_object(game->player) == NO_ID){

    if(player_set_object(game->player, id_obj) == ERROR){
      return ERROR;
    }

  if(space_remove_object(s, id_obj) == ERROR){
    return ERROR;
  }

  }

  return OK;
}


STATUS game_command_drop(Game *game){

  Id player_space_id = NO_ID;
  Id object_id = NO_ID;

  if(!game){
    return ERROR;
  }

  player_space_id = game_get_player_location(game);

  /*Comprobación de que el player tenga objeto*/
  object_id = player_get_object(game->player);
  if(object_id == NO_ID){
    return ERROR;
  }

  if(space_set_object(game_get_space(game, player_space_id), object_id) == OK){
    player_set_object(game->player, NO_ID);
  }
  
  return OK;
}