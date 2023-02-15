/**
 * @brief It implements the object module
 *
 * @file object.c
 * @author alejandra palma
 * @version 2.0
 * @date 2-2-2023
 * @copyright GNU Public License
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "object.h"

/**
 * @brief Object
 *
 * This struct stores all the information of a object.
 */
struct _Object
{
  Id id;                    /*!< Id number of the object, it must be unique */
  Id location;              /*!< Location of the object */
  char name[WORD_SIZE + 1]; /*!< Name of the object */
};

/** object_create allocates memory for a new object
 *  and initializes its members
 */
Object *object_create(Id id)
{
  Object *newObject = NULL;

  /* Error control */
  if (id == NO_ID)
    return NULL;

  /*reserves memory for the new object*/
  newObject = (Object *)malloc(sizeof(Object));
  /* error control*/
  if (newObject == NULL)
  {
    return NULL;
  }
  /*initializes the id (with the given id) and the name*/
  newObject->id = id;
  newObject->name[0] = '\0';

  return newObject;
}

/** object_destroy frees the previous memory allocation
 *  for a object
 */
STATUS object_destroy(Object *object)
{
  /*error control*/
  if (!object)
  {
    return ERROR;
  }
  /*frees the allocated memory*/
  free(object);
  object = NULL;
  return OK;
}

/** It gets the id of a object
 */
Id object_get_id(Object *object)
{
  /*error control*/
  if (!object)
  {
    return NO_ID;
  }
  return object->id;
}

/** It sets the id of an object
 */
STATUS object_set_id(Object *object, Id id)
{
  /*error control*/
  if (!object || !id)
  {
    return ERROR;
  }
  /*sets a given id*/
  object->id = id;
  return OK;
}

/** It sets the name of a object
 */
STATUS object_set_name(Object *object, char *name)
{
  /*error control*/
  if (!object || !name)
  {
    return ERROR;
  }
  /*sets a given name*/
  if (!strcpy(object->name, name))
  {
    return ERROR;
  }
  return OK;
}

/** It gets the name of a object*/
const char *object_get_name(Object *Object)
{
  if (!Object)
  {
    return NULL;
  }
  return Object->name;
}

/** It gets the location of an object*/
Id object_get_location(Object *object)
{
  /*error control*/
  if (!object)
  {
    return NO_ID;
  }

  return object->location;
}

/** It sets the location of an object*/
STATUS object_set_location(Object *object, BOOL value)
{
  /*error control*/
  if (!object)
  {
    return ERROR;
  }
  /*the new location is the given value*/
  object->location = value;

  return OK;
}

/** It prints the object information
 */
STATUS object_print(Object *object)
{

  /* Error Control */
  if (!object)
  {
    return ERROR;
  }

  /* 1. Print the id and the name of the object */
  fprintf(stdout, "--> Object (Id: %ld; Name: %s)\n", object->id, object->name);

  return OK;
}