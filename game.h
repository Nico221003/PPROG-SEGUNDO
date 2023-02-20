/**
 * @brief It defines the game interface
 *
 * @file game.h
 * @author Profesores PPROG
 * @version 2.0
 * @date 29-11-2021
 * @copyright GNU Public License
 */

#ifndef GAME_H
#define GAME_H

#include "command.h"
#include "space.h"
#include "object.h"
#include "player.h"
#include "types.h"

typedef struct _Game {
  Object *object;
  Player *player;
  Space *spaces[MAX_SPACES];
  T_Command last_cmd;
} Game;


/**
 * @brief Creates the game and its elements (calls other create functs) + sets locations
 * 
 * @param game pointer to the game struct
 * @return OK or ERROR in case of error
 */
STATUS game_create(Game *game);


/**
 * @brief Reads the command introduced by the user
 * 
 * @param game pointer to the game struct
 * @param cmd the command introduced on the game
 * @return OK or ERROR in case of error
 */
STATUS game_update(Game *game, T_Command cmd);


/**
 * @brief Destroys the game and its elements, freeing memory
 * 
 * @param game pointer to the game struct
 * @return OK or ERROR in case of error
 */
STATUS game_destroy(Game *game);


/**
 * @brief sets the location of the player in the game
 * 
 * @param game pointer to the game struct
 * @param id id of the space
 * @return OK or ERROR in case of error
 */
STATUS game_set_player_location(Game *game, Id id);


/**
 * @brief sets the location of the object in the game
 * 
 * @param game pointer to the game struct
 * @param id id of the space
 * @return OK or ERROR in case of error
 */
STATUS game_set_object_location(Game *game, Id id);


/**
 * @brief Determines if the game is over or not
 * 
 * @param game pointer to the game struct
 * @return TRUE or FALSE
 */
BOOL game_is_over(Game *game);


/**
 * @brief Prints the data of the game
 * 
 * @param game pointer to the game struct
 */
void game_print_data(Game *game);


/**
 * @brief tbh i don´t even know
 */
Space *game_get_space(Game *game, Id id);


/**
 * @brief Gets the location of the player in the game
 * 
 * @param game pointer to the game struct
 * @return id of the location of the player
 */
Id game_get_player_location(Game *game);


/**
 * @brief Gets the location of the object in the game
 * 
 * @param game pointer to the game struct
 * @return id of the location of the object
 */
Id game_get_object_location(Game *game);


/**
 * @brief Self explanatory (gets last command introduced by the user)
 * 
 * @param game pointer to the game Struct
 * @return last_cmd
 */
T_Command game_get_last_command(Game *game);
#endif
