#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "game_reader.h"


STATUS game_reader_create_from_file(Game *game, char *filename) {

  if (game_create(game) == ERROR) {
    return ERROR;
  }

  if (game_reader_load_spaces(game, filename) == ERROR){
    return ERROR;
  }

  if(game_reader_load_objects(game, filename) == ERROR){
    return ERROR;
  }


  /* The player is located in the first space
  game_set_player_location(game, game_reader_get_space_id_at(game, 0));*/

  return OK;
}


STATUS game_reader_add_space(Game *game, Space *space){
  int i = 0;

  if (space == NULL) {
    return ERROR;
  }

  while (i < MAX_SPACES && game->spaces[i] != NULL) {
    i++;
  }

  if (i >= MAX_SPACES) {
    return ERROR;
  }

  game->spaces[i] = space;

  return OK;
}


STATUS game_reader_add_object(Game *game, Object *object){

  int i = 0;

  if (object == NULL || game == NULL){
    return ERROR;
  }


  /* Como mucho 1 objeto por espacio type of comprobación*/
  /*if (i >= MAX_SPACES){
    return ERROR;
  }*/

  while(i<MAX_OBJ && game->object[i] != NULL){
    i++;
  }

  /*Metemos el objeto en la posición de array que le toque*/
  game->object[i] = object;

  return OK;
}



STATUS game_reader_load_spaces(Game *game, char *filename) {
  FILE *file = NULL;
  char line[WORD_SIZE] = "";
  char name[WORD_SIZE] = "";
  char *toks = NULL;
  Id id = NO_ID, north = NO_ID, east = NO_ID, south = NO_ID, west = NO_ID;
  Space *space = NULL;
  STATUS status = OK;

  if (!filename) {
    return ERROR;
  }

  file = fopen(filename, "r");
  if (file == NULL) {
    return ERROR;
  }

  while (fgets(line, WORD_SIZE, file)) {
    if (strncmp("#s:", line, 3) == 0) {
      toks = strtok(line + 3, "|");
      id = atol(toks);
      toks = strtok(NULL, "|");
      strcpy(name, toks);
      toks = strtok(NULL, "|");
      north = atol(toks);
      toks = strtok(NULL, "|");
      east = atol(toks);
      toks = strtok(NULL, "|");
      south = atol(toks);
      toks = strtok(NULL, "|");
      west = atol(toks);
#ifdef DEBUG
      printf("Leido: %ld|%s|%ld|%ld|%ld|%ld\n", id, name, north, east, south, west);
#endif
      space = space_create(id);
      if (space != NULL) {
        space_set_name(space, name);
        space_set_north(space, north);
        space_set_east(space, east);
        space_set_south(space, south);
        space_set_west(space, west);
        game_reader_add_space(game, space);
      }
    }
  }

  if (ferror(file)) {
    status = ERROR;
  }

  fclose(file);

  return status;
}


STATUS game_reader_load_objects(Game* game, char* filename){

  FILE* file = NULL;

  char line[WORD_SIZE] = "";
  char* toks = NULL;
  
  Id id = NO_ID;
  char name[WORD_SIZE] = "";
  Id location = NO_ID;
  
  Object* object = NULL;
  STATUS status = OK;
  
  if (!filename) {
    return ERROR;
  }
  
  file = fopen(filename, "r");
  if (file == NULL) {
    return ERROR;
  }
  
  while (fgets(line, WORD_SIZE, file)) {

    if (strncmp("#o:", line, 3) == 0) {
      
      toks = strtok(line + 3, "|");
      id = atol(toks);
      
      toks = strtok(NULL, "|");
      strcpy(name, toks);
      
      toks = strtok(NULL, "|");
      location = atol(toks);
 
#ifdef DEBUG
      printf("Leido: %ld|%s|%ld\n", id, name, location);
#endif
         
      object = object_create(id);
      if (location != NO_ID){
        object_set_name(object, name);
        game_set_object_location(game, location, id);
        game_reader_add_object(game, object);
      }
    }
  }

  if (ferror(file)) {
    status = ERROR;
  }
  
  fclose(file);
  
  return status;
}