#include "game.h"
#include "space.h"
#include "types.h"

#ifndef GAME_READER_H
#define GAME_READER_H

STATUS game_reader_add_space(Game *game, Space *space);
Id game_reader_get_space_id_at(Game *game, int position);

STATUS game_reader_create_from_file(Game *game, char *filename);

STATUS game_reader_load_spaces(Game *game, char *filename);


#endif