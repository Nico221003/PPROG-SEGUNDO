/**
 * @brief It declares the tests for the enemy module
 *
 * @file enemy_test.h
 * @author Alejandra Palma
 * @version 2.0
 * @date 10-03-2023
 * @copyright GNU Public License
 */

#ifndef ENEMY_TEST_H
#define ENEMY_TEST_H

/**
 * @test Test enemy creation
 * @pre enemy ID
 * @post Non NULL pointer to enemy
 */
void test1_enemy_create();

/**
 * @test Test enemy creation
 * @pre enemy ID
 * @post enemy_ID == Supplied enemy Id
 */
void test2_enemy_create();

/**
 * @test Test function for enemy_set_name setting
 * @pre String with enemy name
 * @post Ouput==OK
 */
void test1_enemy_set_name();

/**
 * @test Test function for enemy_set_name setting
 * @pre pointer to enemy = NULL
 * @post Output==ERROR
 */
void test2_enemy_set_name();
/**
 * @test Test function for enemy_get_id setting
 * @pre pointer to enemy = 25 (point to enemy = 25)
 * @post Output== 25
 */
void test1_enemy_get_id();
/**
 * @test Test function for enemy_get_id setting
 * @pre pointer to enemy = NULL (point to enemy = NULL)
 * @post Output== NO_ID
 */
void test2_enemy_get_id();

/**
 * @test Test function for enemy_get_name setting
 * @pre pointer to enemy = 1 (point to enemy = 1)
 * @post Output== 0
 */
void test1_enemy_get_name();
/**
 * @test Test function for enemy_get_name setting
 * @pre pointer to enemy = NULL (point to enemy = NULL)
 * @post Output== NULL
 */
void test2_enemy_get_name();

/**
 * @test Test function for enemy_get_object setting
 * @pre pointer to enemy = NULL (point to enemy = NULL)
 * @post Output== FALSE
 */
void test3_enemy_get_object();
/**
 * @test Test function for enemy_destroy setting
 * @pre pointer to enemy = 1 (point to enemy = 1)
 * @post Output== OK
 */
void test1_enemy_destroy();
/**
 * @test Test function for enemy_destroy setting
 * @pre pointer to enemy = NULL (point to enemy = NULL)
 * @post Output== ERROR
 */
void test2_enemy_destroy();
/**
 * @test Test function for enemy_get_health setting
 * @pre pointer to enemy = 1 (point to enemy = 1)
 * @post Output== 5
 */
void test1_enemy_get_health();
/**
 * @test Test function for enemy_get_health setting
 * @pre pointer to enemy = NULL (point to enemy = NULL)
 * @post Output== ERROR
 */
void test2_enemy_get_health();
/**
 * @test Test function for enemy_set_health setting
 * @pre pointer to enemy = 1 (point to enemy = 1)
 * @post Output== 5
 */
void test1_enemy_set_health();
/**
 * @test Test function for enemy_get_health setting
 * @pre pointer to enemy = NULL (point to enemy = NULL)
 * @post Output== ERROR
 */
void test2_enemy_set_health();
/**
 * @test Test function for enemy_get_location setting
 * @pre pointer to enemy = 1 (point to enemy = 1)
 * @post Output== NO_ID
 */
void test1_enemy_get_location();
/**
 * @test Test function for enemy_get_location setting
 * @pre pointer to enemy = NULL (point to enemy = NULL)
 * @post Output== ERROR
 */
void test2_enemy_get_location();
/**
 * @test Test function for enemy_set_location setting
 * @pre pointer to enemy = 1 (point to enemy = 1)
 * @post Output== OK
 */
void test1_enemy_set_location();
/**
 * @test Test function for enemy_set_location setting
 * @pre pointer to enemy = NULL (point to enemy = NULL)
 * @post Output== ERROR
 */
void test2_enemy_set_location();
/**
 * @test Test function for enemy_print setting
 * @pre pointer to enemy = 1 (point to enemy = 1)
 * @post Output== OK
 */
void test1_enemy_print();
/**
 * @test Test function for enemy_print setting
 * @pre pointer to enemy = NULL (point to enemy = NULL)
 * @post Output== ERROR
 */
void test2_enemy_print();

#endif