/**
 * @brief It defines the set interface
 *
 * @file set.h
 * @author Nicolás Ruiz
 * @version 2.0
 * @date 02/03/2023
 * @copyright GNU Public License
 */


#ifndef SET_H
#define SET_H


#include "types.h"


typedef struct _Set Set;


/**
 * @brief Creates a new set, allocating memory and initializing
 * @author Nicolás Ruiz
 * 
 * @return a new set, initialized
 */
Set* set_create();


Set* set_destroy(Set *set);


STATUS set_add(Set *set, Id id);


STATUS set_delete(Set *set, Id id);


BOOL set_is_there(Set *set, Id id);


/**
  * @brief Checks if the array of ids of the Set structure is empty
  * @author Nicolás Ruiz
  *
  * @param set pointer to the Set structure
  * @return TRUE if it is empty or FALSE in other case
  */
BOOL set_empty (Set *set);


STATUS set_print(Set *set);

#endif