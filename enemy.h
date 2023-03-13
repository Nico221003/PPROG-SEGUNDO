/**
 * @brief It defines the enemy interface
 *
 * @file enemy.h
 * @author Alejandra Palma
 * @version 2.0
 * @date 23/02/2023
 * @copyright GNU Public License
 */

#ifndef ENEMY_H
#define ENEMY_H

#define ENEMY_ID 11

#include "types.h"

typedef struct _Enemy Enemy;

/**
 * @brief Creates a new enemy, allocating memory and initializing his camps
 * @author Alejandra Palma
 *
 * @param id the identification of the new enemy
 * @return a new enemy, initialized
 */
Enemy *enemy_create(Id id);

/**
 * @brief Destroys a enemy, freeing memory
 * @author Alejandra Palma
 *
 * @param enemy pointer to the enemy to be freed
 * @return OK if everything went well, or ERROR in case of error
 */
STATUS enemy_destroy(Enemy *enemy);

/**
 * @brief It gets the id of the enemy
 * @author Alejandra Palma
 *
 * @param enemy pointer to the enemy
 * @return the id of the enemy
 */
Id enemy_get_id(Enemy *enemy);

/**
 * @brief It gets the name of the enemy
 * @author Alejandra Palma
 *
 * @param enemy pointer to the enemy
 * @return the name of the enemy
 */
const char *enemy_get_name(Enemy *enemy);

/**
 * @brief It sets the name of the enemy
 * @author Alejandra Palma
 *
 * @param enemy pointer to the enemy
 * @param name of the enemy to be setted
 * @return OK if everything went well or ERROR in case of error
 */
STATUS enemy_set_name(Enemy *enemy, char *name);

/**
 * @brief It gets the health of the enemy
 * @author Alejandra Palma
 *
 * @param enemy pointer to the enemy
 * @return the health of the enemy
 */
int enemy_get_health(Enemy *enemy);

/**
 * @brief It sets the health of the enemy
 * @author Alejandra Palma
 *
 * @param enemy pointer to the enemy
 * @param health health to be setted in the enemy struct
 * @return OK if everything went well or ERROR in case of error
 */
STATUS enemy_set_health(Enemy *enemy, int health);

/**
 * @brief It gets the location of the enemy
 * @author Alejandra Palma
 *
 * @param enemy pointer to the enemy
 * @return the location of the enemy
 */
Id enemy_get_location(Enemy *enemy);

/**
 * @brief It sets the location of the enemy
 * @author Alejandra Palma
 *
 * @param enemy pointer to the enemy
 * @param id id of the location where the enemy is setted
 * @return OK if everything went well or ERROR in case of error
 */
STATUS enemy_set_location(Enemy *enemy, Id id);

/**
 * @brief prints the info of the enemy
 * @author Alejandra Palma
 *
 * @param enemy pointer to the enemy
 * @return OK if everything went well or ERROR in case of error
 */
STATUS enemy_print(Enemy *enemy);

#endif
