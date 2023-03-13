/**
 * @brief It implements the enemy module
 *
 * @file enemy.c
 * @author Alejandra Palma
 * @version 2.0
 * @date 23/02/2023
 * @copyright GNU Public License
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "enemy.h"

/**
 * @brief Enemy struct
 *
 * This struct stores all the information of an enemy.
 */
struct _Enemy
{
    Id id;                    /*!< Id number of the enemy, it must be unique */
    char name[WORD_SIZE + 1]; /*!< Name of the enemy */
    Id location;              /*!< Location of the enemy */
    Id object;                /*!< Object the enemy carrries */
    int health;               /*!< Health of the enemy */
};

Enemy *enemy_create(Id id)
{

    Enemy *newEnemy = NULL;

    /* Error control */
    if (id == NO_ID)
        return NULL;

    newEnemy = (Enemy *)malloc(sizeof(Enemy));
    if (newEnemy == NULL)
    {
        return NULL;
    }

    /* Initialization of an empty enemy*/
    newEnemy->id = id;
    newEnemy->name[0] = '\0';
    newEnemy->location = NO_ID;
    newEnemy->object = NO_ID;
    newEnemy->health = 5;

    return newEnemy;
}

STATUS enemy_destroy(Enemy *enemy)
{

    if (!enemy)
    {
        return ERROR;
    }

    free(enemy);
    enemy = NULL;

    return OK;
}

/*Id*/
Id enemy_get_id(Enemy *enemy)
{

    if (!enemy)
    {
        return NO_ID;
    }

    return enemy->id;
}

/*Nombre*/
const char *enemy_get_name(Enemy *enemy)
{

    if (!enemy)
    {
        return NULL;
    }

    return enemy->name;
}

STATUS enemy_set_name(Enemy *enemy, char *name)
{

    if (!enemy || !name)
    {
        return ERROR;
    }

    if (!strcpy(enemy->name, name))
    {
        return ERROR;
    }

    return OK;
}


/*Health*/
int enemy_get_health(Enemy *enemy)
{

    if (!enemy)
    {
        return ERROR;
    }

    return enemy->health;
}

STATUS enemy_set_health(Enemy *enemy, int health)
{

    if (!enemy)
    {
        return ERROR;
    }

    enemy->health = health;

    return OK;
}

/*Location*/
Id enemy_get_location(Enemy *enemy)
{

    if (!enemy)
    {
        return NO_ID;
    }

    return enemy->location;
}

STATUS enemy_set_location(Enemy *enemy, Id id)
{

    if (!enemy)
    {
        return ERROR;
    }

    enemy->location = id;

    return OK;
}

/*Print*/

STATUS enemy_print(Enemy *enemy)
{

    Id idaux = NO_ID;

    if (!enemy)
    {
        return ERROR;
    }

    /* 1. Print the id and the name of the enemy */
    fprintf(stdout, "--> Enemy (Id: %ld; Name: %s)\n", enemy->id, enemy->name);

    /* 2. Print the location of the enemy*/
    idaux = enemy_get_location(enemy);
    if (NO_ID != idaux)
    {
        fprintf(stdout, "---> Enemy location is %ld", idaux);
    }
    else
    {
        return ERROR;
    }


    /* 4. Print if the enemy´s health */
    fprintf(stdout, "---> Enemy health is %d .\n", enemy->health);

    return OK;
}