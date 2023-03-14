/**
  * @brief It defines a textual graphic engine
 *
 * @file graphic_engine.c
 * @author Profesores PPROG
 * @version 2.0
 * @date 29-11-2021
 * @copyright GNU Public License
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "graphic_engine.h"

#define ROWS 39
#define COLUMNS 93

struct _Graphic_engine {
  Area *map, *descript, *banner, *help, *feedback;
};


/*-----------FUNCIÓN PRIVADA------------*/
void graphic_engine_get_string_objects(char *objects, Game *game, Id space_id);
/*--------------------------------------*/

Graphic_engine *graphic_engine_create() {
  static Graphic_engine *ge = NULL;

  if (ge) {
    return ge;
  }

  screen_init(ROWS, COLUMNS);
  ge = (Graphic_engine *)malloc(sizeof(Graphic_engine));
  if (ge == NULL) {
    return NULL;
  }

  ge->map = screen_area_init(1, 1, 59, 28);
  ge->descript = screen_area_init(61, 1, 30, 28);
  ge->banner = screen_area_init(28, 30, 23, 1);
  ge->help = screen_area_init(1, 31, 91, 3);
  ge->feedback = screen_area_init(1, 35, 91, 3);

  return ge;
}

void graphic_engine_destroy(Graphic_engine *ge) {
  if (!ge)
    return;

  screen_area_destroy(ge->map);
  screen_area_destroy(ge->descript);
  screen_area_destroy(ge->banner);
  screen_area_destroy(ge->help);
  screen_area_destroy(ge->feedback);

  screen_destroy();
  free(ge);
}

void graphic_engine_paint_game(Graphic_engine *ge, Game *game){

  Id id_act = NO_ID, id_back = NO_ID, id_next = NO_ID, id_east = NO_ID, id_west = NO_ID;
  Id obj_loc = NO_ID;   /*id del space donde está el objeto*/
  Id id_obj = NO_ID;    /*id de un objeto en específico*/
  char dirLeft, dirRight;

  int i=0;

  Space *space_act = NULL;

  char str[255];
  extern char *cmd_to_str[N_CMD][N_CMDT];

  T_Command last_cmd = UNKNOWN;

  /*id = 21, pantalla = "o21", cadena final = "o21 "(4 caracteres con el espacio)  =>  MAX_OBJ * 4 + 1 (final de cadena)*/
  char cadenaObjs[MAX_OBJ * 4 + 1];
  char cadenaEnemy[7] = "/\\oo/\\";

  /* Paint the in the map area */
  screen_area_clear(ge->map);
  if ((id_act = game_get_player_location(game)) != NO_ID) {
    space_act = game_get_space(game, id_act);
    id_back = space_get_north(space_act);
    id_next = space_get_south(space_act);
    id_east = space_get_east(space_act);
    id_west = space_get_west(space_act);


    /*ID BACK*/
    graphic_engine_get_string_objects(cadenaObjs, game, id_back);

    if (game_get_enemy_location(game) == id_back && game_get_enemy_health(game) != 0){
      strcpy(cadenaEnemy, "/\\oo/\\");
    }else{
      strcpy(cadenaEnemy, "      ");
    }

    if (id_back != NO_ID) {
      sprintf(str, "  +----------------+");
      screen_area_puts(ge->map, str);
      sprintf(str, "  |             %3d|", (int)id_back);
      screen_area_puts(ge->map, str);
      sprintf(str, "  |                |");
      screen_area_puts(ge->map, str);
      sprintf(str, "  |     %s     |", cadenaEnemy);
      screen_area_puts(ge->map, str);
      sprintf(str, "  |                |");
      screen_area_puts(ge->map, str);
      sprintf(str, "  |%s|", cadenaObjs);
      screen_area_puts(ge->map, str);
      sprintf(str, "  +----------------+");
      screen_area_puts(ge->map, str);
      sprintf(str, "        ^");
      screen_area_puts(ge->map, str);
    }


    /*ID ACT*/
    graphic_engine_get_string_objects(cadenaObjs, game, id_act);
    
    if (game_get_enemy_location(game) == id_act && game_get_enemy_health(game) != 0){
      strcpy(cadenaEnemy, "/\\oo/\\");
    }else{
      strcpy(cadenaEnemy, "      ");
    }

		
    if (id_act != NO_ID) {
      if (id_west != NO_ID)
        dirLeft = '<';
      else {
        dirLeft = ' ';
      }
      if (id_east != NO_ID)
        dirRight = '>';
      else {
        dirRight = ' ';
      }
      sprintf(str, "  +----------------+");
      screen_area_puts(ge->map, str);
      sprintf(str, "  | m0^         %3d|", (int)id_act);
      screen_area_puts(ge->map, str);
      sprintf(str, " %c|                |%c  ", dirLeft, dirRight);
      screen_area_puts(ge->map, str);
      sprintf(str, "  |     %s     |", cadenaEnemy);
			screen_area_puts(ge->map, str);
      sprintf(str, "  |                |");
      screen_area_puts(ge->map, str);
			sprintf(str, "  |%s|", cadenaObjs);
      screen_area_puts(ge->map, str);
      sprintf(str, "  +----------------+");
      screen_area_puts(ge->map, str);
    }


    /*ID NEXT*/
    graphic_engine_get_string_objects(cadenaObjs, game, id_next);

    if (game_get_enemy_location(game) == id_next && game_get_enemy_health(game) != 0){
      strcpy(cadenaEnemy, "/\\oo/\\");
    }else{
      strcpy(cadenaEnemy, "      ");
    }

    if (id_next != NO_ID) {
      sprintf(str, "        v");
      screen_area_puts(ge->map, str);
      sprintf(str, "  +----------------+");
      screen_area_puts(ge->map, str);
      sprintf(str, "  |             %3d|", (int)id_next);
      screen_area_puts(ge->map, str);
      sprintf(str, "  |                |");
      screen_area_puts(ge->map, str);
      sprintf(str, "  |     %s     |", cadenaEnemy);
      screen_area_puts(ge->map, str);
      sprintf(str, "  |                |");
      screen_area_puts(ge->map, str);
      sprintf(str, "  |%s|", cadenaObjs);
      screen_area_puts(ge->map, str);
      sprintf(str, "  +----------------+");
      screen_area_puts(ge->map, str);

			}
		}


  /* Paint in the description area */
  screen_area_clear(ge->descript);

  sprintf(str, "          INFORMATION");
  screen_area_puts(ge->descript, str);
  sprintf(str, " ----------------------------");
  screen_area_puts(ge->descript, str);

  /*objects*/
  sprintf(str, " OBJETOS");
  screen_area_puts(ge->descript, str);

  for (i = 0; i < MAX_OBJ && game->object[i] != NULL; i++){

    if(object_get_id(game->object[i]) != NO_ID){

      id_obj = object_get_id(game->object[i]);
      obj_loc = game_get_object_location(game, id_obj);

      sprintf(str, " -Objecto %ld - location: %ld", id_obj, obj_loc);
      screen_area_puts(ge->descript, str);

    }

  }

  sprintf(str, " ");
  screen_area_puts(ge->descript, str);

  /*player*/
  sprintf(str, " PLAYER");
  screen_area_puts(ge->descript, str);

  sprintf(str, " -Id: %ld", player_get_id(game->player));
  screen_area_puts(ge->descript, str);
  sprintf(str, " -Location: %ld", game_get_player_location(game));
  screen_area_puts(ge->descript, str);
  sprintf(str, " -Health: %d", game_get_player_health(game));
  screen_area_puts(ge->descript, str);
  sprintf(str, " -Player object: %ld", player_get_object(game->player));  /*Mal encapsulamiento, cambiar en cuanto se pueda*/
  screen_area_puts(ge->descript, str);

  sprintf(str, " ");
  screen_area_puts(ge->descript, str);

  /*enemy*/
  sprintf(str, " ENEMY");
  screen_area_puts(ge->descript, str);

  sprintf(str, " -Id: %ld", enemy_get_id(game->enemy));
  screen_area_puts(ge->descript, str);
  if(game_get_enemy_health(game) == 0){
    sprintf(str, " -Location: ENEMY IS DEAD");
    screen_area_puts(ge->descript, str);
  }
  else{
    sprintf(str, " -Location: %ld", game_get_enemy_location(game));
    screen_area_puts(ge->descript, str);
  }
  sprintf(str, " -Health: %d", game_get_enemy_health(game));
  screen_area_puts(ge->descript, str);

  sprintf(str, " ");
  screen_area_puts(ge->descript, str);

  /* Paint in the banner area */
  screen_area_puts(ge->banner, "    The anthill game ");

  /* Paint in the help area */
  screen_area_clear(ge->help);
  sprintf(str, " The commands you can use are:");
  screen_area_puts(ge->help, str);
  sprintf(str, "  next or n, back or b, left or l, right or r, attack or a, take or t, drop or d, exit or e");
  screen_area_puts(ge->help, str);

  /* Paint in the feedback area */
  last_cmd = game_get_last_command(game);
  if (game->state == OK){
    sprintf(str, " %s (%s) : OK", cmd_to_str[last_cmd - NO_CMD][CMDL], cmd_to_str[last_cmd - NO_CMD][CMDS]);
    screen_area_puts(ge->feedback, str);
  }else{
    sprintf(str, " %s (%s) : ERROR", cmd_to_str[last_cmd - NO_CMD][CMDL], cmd_to_str[last_cmd - NO_CMD][CMDS]);
    screen_area_puts(ge->feedback, str);
  } 

  /*Juego terminado*/
  if(game_is_over(game) == TRUE){
    sprintf(str, " GAME IS OVER, YOU ARE DEAD");  
  }

  /* Dump to the terminal */
  screen_paint();
  printf("prompt:> ");
}



void graphic_engine_get_string_objects(char *objects, Game *game, Id space_id){

  int i, len;
  char obj[7];
	Id id_obj;
  Id id_loc;

	strcpy(objects, "");

  for(i=0; i<MAX_OBJ && game->object[i] != NULL; i++){

    id_obj = object_get_id(game->object[i]);
    id_loc = game_get_object_location(game, id_obj);

    if(id_loc == space_id){
      sprintf(obj, "o%ld ", id_obj);
      strcat(objects, obj);
    }

  }

  len = strlen(objects);

  for(i=len; i<16; i++){
    objects[i] = ' ';
  }

  objects[i] = '\0';

  return;
}