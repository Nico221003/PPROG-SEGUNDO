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

#define PLAYER_ID 1

#include "types.h"

typedef struct _Player Player;


/**
 * @brief Creates a new player, allocating memory and initializing his camps
 * @author Nicolás Ruiz
 * 
 * @param id the identification of the new player
 * @return a new player, initialized
 */
Player* player_create(Id id);


/**
 * @brief Destroys a player, freeing memory
 * @author Nicolás Ruiz
 * 
 * @param player pointer to the player to be freed
 * @return OK if everything went well, or ERROR in case of error
 */
STATUS player_destroy(Player* player);


/**
 * @brief It gets the id of the player
 * @author Nicolás Ruiz
 * 
 * @param player pointer to the player 
 * @return the id of the player
 */
Id player_get_id(Player* player);


/**
 * @brief It gets the name of the player
 * @author Nicolás Ruiz
 * 
 * @param player pointer to the player 
 * @return the name of the player
 */
const char * player_get_name(Player* player);


/**
 * @brief It sets the name of the player
 * @author Nicolás Ruiz
 * 
 * @param player pointer to the player
 * @param name of the player to be setted
 * @return OK if everything went well or ERROR in case of error
 */
STATUS player_set_name(Player* player, char* name);


/**
 * @brief It gets the object of the player
 * @author Nicolás Ruiz
 * 
 * @param player pointer to the player 
 * @return the object of the player
 */
Id player_get_object(Player* player);


/**
 * @brief It sets the object of the player
 * @author Nicolás Ruiz
 * 
 * @param player pointer to the player
 * @param id id of the object to be setted in the player struct
 * @return OK if everything went well or ERROR in case of error
 */
STATUS player_set_object(Player* player, Id id);


/**
 * @brief It gets the location of the player
 * @author Nicolás Ruiz
 * 
 * @param player pointer to the player 
 * @return the location of the player
 */
Id player_get_location(Player* player);


/**
 * @brief It sets the location of the player
 * @author Nicolás Ruiz
 * 
 * @param player pointer to the player
 * @param id id of the location where the player is setted
 * @return OK if everything went well or ERROR in case of error
 */
STATUS player_set_location(Player* player, Id id);


/**
 * @brief prints the info of the player
 * 
 * @param player pointer to the player
 * @return OK if everything went well or ERROR in case of error
 */
STATUS player_print(Player* player);


#endif