/**
 * @brief It defines the player interface
 *
 * @file space.h
 * @author Nicolás Ruiz
 * @version 2.0
 * @date 07/02/2023
 * @copyright GNU Public License
 */



#ifndef PLAYER_H
#define PLAYER_H

#include "types.h"

typedef struct _Player Player;


Player* player_create(Id id);


STATUS player_destroy(Player* player);


Id player_get_id(Player* player);


const char * player_get_name(Player* player);


STATUS player_set_name(Player* player, char* name);


BOOL player_get_object(Player* player);


STATUS player_set_object(Player* player, BOOL value);


Id player_get_location(Player* player);


STATUS player_set_location(Player* player, BOOL value);


STATUS player_print(Player* player);


#endif