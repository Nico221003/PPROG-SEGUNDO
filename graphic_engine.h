/**
 * @brief It defines the textual graphic engine interface
 *
 * @file graphic_engine.h
 * @author Profesores PPROG
 * @version 2.0
 * @date 29-11-2021
 * @copyright GNU Public License
 */

#ifndef __GRAPHIC_ENGINE__
#define __GRAPHIC_ENGINE__x

#include "libscreen.h"
#include "game.h"
#include "command.h"
#include "space.h"
#include "types.h"

typedef struct _Graphic_engine Graphic_engine;


/**
 * @brief Creates the graphic engine for the game, allocating memory for it
 * 
 * @return the new graphic engine
 */
Graphic_engine *graphic_engine_create();


/**
 * @brief Destroys the graphic engine, freeing the allocated memory (calls libscreen.h)
 * 
 * @param ge pointer to the graphic engine
 */
void graphic_engine_destroy(Graphic_engine *ge);


/**
 * @brief Paints all the game with his elements + interfaz elements
 * 
 * @param ge pointer to graphic engige
 * @param game pointer to the game
 */
void graphic_engine_paint_game(Graphic_engine *ge, Game *game);

#endif
