#include "game.h"
#include "space.h"
#include "types.h"

#ifndef GAME_READER_H
#define GAME_READER_H

STATUS game_reader_add_space(Game *game, Space *space);

STATUS game_reader_add_object(Game *game, Object *object);

STATUS game_reader_create_from_file(Game *game, char *filename);

STATUS game_reader_load_spaces(Game *game, char *filename);

STATUS game_reader_load_objects(Game* game, char* filename);


#endif