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
#include "game.h"

/**
   Private functions
*/
void game_command_exit(Game *game);
void game_command_next(Game *game);
void game_command_back(Game *game);
void game_command_take(Game *game);
void game_command_drop(Game *game);
void game_command_left(Game *game);
void game_command_right(Game *game);

/**
   Game interface implementation
*/

STATUS game_create(Game *game)
{
  int i;

  for (i = 0; i < MAX_SPACES; i++)
  {
    game->spaces[i] = NULL;
  }

  /*Creamos los objetos en el juego*/
  game->player = player_create(PLAYER_ID);
  game->object = object_create(OBJECT_ID);
  game->enemy = enemy_create(ENEMY_ID);

  /*game->player_location = NO_ID;
  game->object_location = NO_ID;*/

  game_set_player_location(game, 11);
  game_set_object_location(game, 11);
  game_set_enemy_location(game, 11);

  game->last_cmd = NO_CMD;

  return OK;
}

STATUS game_destroy(Game *game)
{
  int i = 0;

  for (i = 0; i < MAX_SPACES && game->spaces[i] != NULL; i++)
  {
    space_destroy(game->spaces[i]);
  }

  object_destroy(game->object);
  player_destroy(game->player);

  return OK;
}

Space *game_get_space(Game *game, Id id)
{
  int i = 0;

  if (id == NO_ID)
  {
    return NULL;
  }

  for (i = 0; i < MAX_SPACES && game->spaces[i] != NULL; i++)
  {
    if (id == space_get_id(game->spaces[i]))
    {
      return game->spaces[i];
    }
  }

  return NULL;
}

STATUS game_set_player_location(Game *game, Id id)
{
  if (id == NO_ID)
  {
    return ERROR;
  }

  /*game->player_location = id;*/

  player_set_location(game->player, id);

  return OK;
}

STATUS game_set_enemy_location(Game *game, Id id)
{
  if (id == NO_ID)
  {
    return ERROR;
  }

  /*game->player_location = id;*/

  enemy_set_location(game->enemy, id);

  return OK;
}

STATUS game_set_object_location(Game *game, Id id)
{

  int aux = 0;

  if (id == NO_ID)
  {
    return ERROR;
  }

  /*game->object_location = id;*/

  object_set_location(game->object, id);
  aux = space_set_object(game_get_space(game, id), TRUE);

  if (aux == ERROR)
  {
    return ERROR;
  }

  return OK;
}

Id game_get_player_location(Game *game)
{

  if (!game)
  {
    return NO_ID;
  }

  /*return game->player_location;*/

  return player_get_location(game->player);
}

int game_get_player_health(Game *game)
{

  if (!game)
  {
    return NO_ID;
  }

  /*return game->player_health;*/

  return player_get_health(game->player);
}

Id game_get_enemy_location(Game *game)
{

  if (!game)
  {
    return NO_ID;
  }

  /*return game->player_location;*/

  return enemy_get_location(game->enemy);
}

int game_get_enemy_health(Game *game)
{

  if (!game)
  {
    return NO_ID;
  }

  /*return game->player_health;*/

  return enemy_get_health(game->enemy);
}

Id game_get_object_location(Game *game)
{

  if (!game)
  {
    return NO_ID;
  }

  /*return game->object_location;*/

  return object_get_location(game->object);
}

STATUS game_update(Game *game, T_Command cmd)
{
  game->last_cmd = cmd;

  switch (cmd)
  {
    case ATTACK:
    game_command_attack(game);
    break;
    

  case LEFT:
    game_command_left(game);
    break;

  case RIGHT:
    game_command_right(game);
    break;

  case EXIT:
    game_command_exit(game);
    break;

  case NEXT:
    game_command_next(game);
    break;

  case BACK:
    game_command_back(game);
    break;

  case TAKE:
    game_command_take(game);
    break;

  case DROP:
    game_command_drop(game);
    break;

  default:
    break;
  }

  return OK;
}

T_Command game_get_last_command(Game *game)
{
  return game->last_cmd;
}

void game_print_data(Game *game)
{
  int i = 0;

  printf("\n\n-------------\n\n");

  printf("=> Spaces: \n");
  for (i = 0; i < MAX_SPACES && game->spaces[i] != NULL; i++)
  {
    space_print(game->spaces[i]);
  }

  /*printf("=> Object location: %d\n", (int)game->object_location);*/
  printf("=> Object location: %d\n", (int)object_get_location(game->object));

  /*printf("=> Player location: %d\n", (int)game->player_location);*/
  printf("=> Player location: %d\n", (int)player_get_location(game->player));

  
}

BOOL game_is_over(Game *game)
{

  if ((player_get_health(game->player)) == 0)
    return ERROR;

  return FALSE;
}

/**
   Calls implementation for each action
*/
void game_command_attack(Game *game)
{
  
  Id space_id = NO_ID;
  Id enemy_id = NO_ID;

  space_id = game_get_player_location(game);
  if (space_id == NO_ID)
  {
    return;
  }
  enemy_id= game_get_enemy_location(game);
  if (enemy_id == NO_ID)
  {
    return;
  }

  if( space_id == enemy_id){
    int r = random () % 10;
    if(r<=4 && r>=0)
    game->player->health = game_get_player_health(game->player)-1;
  }

  current_id = space_get_west(game_get_space(game, space_id));
  if (current_id != NO_ID)
  {
    game_set_player_location(game, current_id);
  }

  return;
}

void game_command_left(Game *game)
{
  Id current_id = NO_ID;
  Id space_id = NO_ID;

  space_id = game_get_player_location(game);
  if (space_id == NO_ID)
  {
    return;
  }

  current_id = space_get_west(game_get_space(game, space_id));
  if (current_id != NO_ID)
  {
    game_set_player_location(game, current_id);
  }

  return;
}

void game_command_right(Game *game)
{
  Id current_id = NO_ID;
  Id space_id = NO_ID;

  space_id = game_get_player_location(game);
  if (space_id == NO_ID)
  {
    return;
  }

  current_id = space_get_east(game_get_space(game, space_id));
  if (current_id != NO_ID)
  {
    game_set_player_location(game, current_id);
  }

  return;
}

void game_command_exit(Game *game)
{
}

void game_command_next(Game *game)
{
  Id current_id = NO_ID;
  Id space_id = NO_ID;

  space_id = game_get_player_location(game);
  if (space_id == NO_ID)
  {
    return;
  }

  current_id = space_get_south(game_get_space(game, space_id));
  if (current_id != NO_ID)
  {
    game_set_player_location(game, current_id);
  }

  return;
}

void game_command_back(Game *game)
{
  Id current_id = NO_ID;
  Id space_id = NO_ID;

  space_id = game_get_player_location(game);

  if (NO_ID == space_id)
  {
    return;
  }

  current_id = space_get_north(game_get_space(game, space_id));
  if (current_id != NO_ID)
  {
    game_set_player_location(game, current_id);
  }

  return;
}

void game_command_take(Game *game)
{

  Id object_id = NO_ID;
  Id playerloc_id = NO_ID;
  Id objectloc_id = NO_ID;

  if (!game)
  {
    return;
  }

  /*Comprobar que player esté en el mismo hab que el objeto*/
  playerloc_id = game_get_player_location(game);
  objectloc_id = game_get_object_location(game);

  if (playerloc_id != objectloc_id)
  {
    return;
  }

  /*Meter id de objeto en player->object y poner object->location a NO_ID*/
  object_id = object_get_id(game->object);
  object_set_location(game->object, NO_ID);

  player_set_object(game->player, object_id);

  return;
}

void game_command_drop(Game *game)
{

  Id objectloc_id = NO_ID;
  Id objectplayer_id = NO_ID;

  if (!game)
  {
    return;
  }

  /*Comprobación de que el objeto no esté en el mapa*/
  objectloc_id = game_get_object_location(game);
  if (objectloc_id != NO_ID)
  {
    return;
  }

  /*Comprobación de que el player tenga objeto*/
  objectplayer_id = player_get_object(game->player);
  if (objectplayer_id == NO_ID)
  {
    return;
  }

  /*Ponemos el objeto del player a NO_ID*/
  /*Seteamos el objeto donde está el player*/
  player_set_object(game->player, NO_ID);

  object_set_location(game->object, player_get_location(game->player));

  return;
}