/** 
 * @brief It implements the player module
 * 
 * @file player.c
 * @author Nicolás Ruiz
 * @version 2.0 
 * @date 07/02/2023
 * @copyright GNU Public License
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "player.h"


/**
 * @brief Player struct
 *
 * This struct stores all the information of a player.
 */
struct _Player {
  Id id;                    /*!< Id number of the player, it must be unique */
  char name[WORD_SIZE + 1]; /*!< Name of the player */
  Id location;              /*!< Location of the player */
  Id object;                /*!< Object the player carrries */
};



Player* player_create(Id id) {

  Player *newPlayer = NULL;

  /* Error control */
  if (id == NO_ID)
    return NULL;

  newPlayer = (Player *) malloc(sizeof (Player));
  if (newPlayer == NULL) {
    return NULL;
  }

  /* Initialization of an empty player*/
  newPlayer->id = id;
  newPlayer->name[0] = '\0';
  newPlayer->location = NO_ID;
  newPlayer->object = NO_ID;

  return newPlayer;
}


STATUS player_destroy(Player* player){

  if (!player) {
    return ERROR;
  }

  free(player);
  player = NULL;

  return OK;
}


/*Id*/
Id player_get_id(Player* player){

  if (!player) {
    return NO_ID;
  }

  return player->id;
}


/*Nombre*/
const char * player_get_name(Player* player){

  if (!player){
    return NULL;
  }

  return player->name;
}

STATUS player_set_name(Player* player, char* name){

  if (!player || !name) {
    return ERROR;
  }

  if (!strcpy(player->name, name)){
    return ERROR;
  }

  return OK;
}


/*Objeto*/
BOOL player_get_object(Player* player){

  if (!player){
    return FALSE;
  }

  return player->object;
}

STATUS player_set_object(Player* player, BOOL value){

  if (!player) {
    return ERROR;
  }

  player->object = value;

  return OK;
}


/*Localización*/
Id player_get_location(Player* player){

  if(!player){
    return NO_ID;
  }

  return player->location;
}

STATUS player_set_location(Player* player, BOOL value){

  if(!player){
    return ERROR;
  }

  player->location = value;

  return OK;
}



STATUS player_print(Player* player){

  Id idaux = NO_ID;

  if (!player) {
    return ERROR;
  }

  /* 1. Print the id and the name of the player */
  fprintf(stdout, "--> Player (Id: %ld; Name: %s)\n", player->id, player->name);

  /* 2. Print the location of the player*/
  idaux = player_get_location(player);
  if(NO_ID != idaux){
    fprintf(stdout, "---> Player location is %ld", idaux);
  }
  else{
    return ERROR;
  }

  /* 3. Print if the player has an object or not */
  if (player_get_object(player)) {
    fprintf(stdout, "---> Player has an object.\n");
  } else {
    fprintf(stdout, "---> Player has no objects.\n");
  }

  return OK;
}