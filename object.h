/**
 * @brief It defines the object interface
 *
 * @file object.h
 * @author Alejandra Palma
 * @version 2.0
 * @date 2-2-2023
 * @copyright GNU Public License
 */

#ifndef OBJECT_H
#define OBJECT_H

#include "types.h"

#define FIRST_OBJECT 1
#define WORD_SIZE 1000

#define OBJECT_ID 1

typedef struct _Object Object;

/**
 * @brief It creates a new object, allocating memory and initializing its memebers
 * @author Alejandra Palma
 *
 * @param id the identification number for the new object
 * @return a new object, initialized
 */
Object *object_create(Id id);

/**
 * @brief It destroys an object, freeing the allocated memory
 * @author Alejandra Palma
 *
 * @param object a pointer to the space that must be destroyed
 * @return OK, if everything goes well or ERROR if there was some mistake
 */

STATUS object_destroy(Object *object);

/**
 * @brief It gets the id of an object
 * @author Alejandra Palma
 *
 * @param object a pointer to the object
 * @return the id of object
 */
Id object_get_id(Object *object);

/**
 * @brief It sets the id of an object
 * @author Alejandra Palma
 *
 * @param Object a pointer to the object
 * @param id a string with the id to store
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
STATUS object_set_id(Object *object, Id id);

/**
 * @brief It sets the name of an object
 * @author Alejandra Palma
 *
 * @param Object a pointer to the object
 * @param name a string with the name to store
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
STATUS object_set_name(Object *object, char *name);

/**
 * @brief It gets the name of an object
 * @author Alejandra Palma
 *
 * @param Object a pointer to the object
 * @return  a string with the name of the object
 */
char *object_get_name(Object *object);

/**
 * @brief It prints the object information
 * @author Alejandra Palma
 *
 * This fucntion shows the id and name of the object.
 * @param Object a pointer to the object
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
STATUS object_print(Object *object);

#endif