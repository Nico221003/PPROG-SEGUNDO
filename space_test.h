/** 
 * @brief It declares the tests for the space module
 * 
 * @file space_test.h
 * @author Profesores Pprog
 * @version 2.0 
 * @date 09-03-2021
 * @copyright GNU Public License
 */

#ifndef SPACE_TEST_H
#define SPACE_TEST_H

/**
 * @test Test space creation
 * @pre Space ID 
 * @post Non NULL pointer to space 
 */
void test1_space_create();

/**
 * @test Test space creation
 * @pre Space ID 
 * @post Space_ID == Supplied Space Id
 */
void test2_space_create();

/**
 * @test Test function for space_name setting
 * @pre String with space name
 * @post Ouput==OK 
 */
void test1_space_set_name();

/**
 * @test Test function for space_name setting
 * @pre pointer to space = NULL 
 * @post Output==ERROR
 */
void test2_space_set_name();

/**
 * @test Test function for space_name setting
 * @pre pointer to space_name = NULL (point to space = NON NULL) 
 * @post Output==ERROR
 */
void test3_space_set_name();
/**
 * @test Test function for space_set_north setting
 * @pre pointer to space_north = 5 (point to space = 5) 
 * @post Output== OK
 */
void test1_space_set_north();
/**
 * @test Test function for space_set_north setting
 * @pre pointer to space = NULL (point to space = NULL) 
 * @post Output== ERROR
 */
void test2_space_set_north();
/**
 * @test Test function for space_set_north setting
 * @pre pointer to space = NULL (point to space = NULL) 
 * @post Output== ERROR
 */
void test3_space_set_north();
/**
 * @test Test function for space_set_north setting
 * @pre pointer to space = 5 (point to space = 5) 
 * @post Output== ERROR
 */
void test4_space_set_north();
/**
 * @test Test function for space_set_south setting
 * @pre pointer to space = 5 (point to space = 5) 
 * @post Output== OK
 */
void test1_space_set_south();
/**
 * @test Test function for space_set_south setting
 * @pre pointer to space = NULL (point to space = NULL) 
 * @post Output== ERROR
 */
void test2_space_set_south();
/**
 * @test Test function for space_set_south setting
 * @pre pointer to space = NULL (point to space = NULL) 
 * @post Output== ERROR
 */
void test3_space_set_south();
/**
 * @test Test function for space_set_south setting
 * @pre pointer to space = 5 (point to space = 5) 
 * @post Output== ERROR
 */
void test4_space_set_south();
/**
 * @test Test function for space_set_east setting
 * @pre pointer to space = 5 (point to space = 5) 
 * @post Output== OK
 */
void test1_space_set_east();
/**
 * @test Test function for space_set_east setting
 * @pre pointer to space = NULL (point to space = NULL) 
 * @post Output== ERROR
 */
void test2_space_set_east();
/**
 * @test Test function for space_set_east setting
 * @pre pointer to space = NULL (point to space = NULL) 
 * @post Output== ERROR
 */
void test3_space_set_east();
/**
 * @test Test function for space_set_east setting
 * @pre pointer to space = 5 (point to space = 5) 
 * @post Output== ERROR
 */
void test4_space_set_east();
/**
 * @test Test function for space_set_west setting
 * @pre pointer to space = 5 (point to space = 5) 
 * @post Output== OK
 */
void test1_space_set_west();
/**
 * @test Test function for space_set_west setting
 * @pre pointer to space = NULL (point to space = NULL) 
 * @post Output== ERROR
 */
void test2_space_set_west();
/**
 * @test Test function for space_set_west setting
 * @pre pointer to space = NULL (point to space = NULL) 
 * @post Output== ERROR
 */
void test3_space_set_west();
/**
 * @test Test function for space_set_west setting
 * @pre pointer to space = 5 (point to space = 5) 
 * @post Output== ERROR
 */
void test4_space_set_west();
/**
 * @test Test function for space_get_id setting
 * @pre pointer to space = 25 (point to space = 25) 
 * @post Output== 25
 */
void test1_space_get_id();
/**
 * @test Test function for space_get_id setting
 * @pre pointer to space = NULL (point to space = NULL) 
 * @post Output== NO_ID
 */
void test2_space_get_id();
/**
 * @test Test function for space_set_object setting
 * @pre pointer to space =1 (point to space = 1) 
 * @post Output== OK
 */
void test1_space_set_object();
/**
 * @test Test function for space_set_object setting
 * @pre pointer to space = NULL (point to space = NULL) 
 * @post Output== ERROR
 */
void test2_space_set_object();
/**
 * @test Test function for space_get_name setting
 * @pre pointer to space = 1 (point to space = 1) 
 * @post Output== 0
 */
void test1_space_get_name();
/**
 * @test Test function for space_get_name setting
 * @pre pointer to space = NULL (point to space = NULL) 
 * @post Output== NULL
 */
void test2_space_get_name();
/**
 * @test Test function for space_get_NORTH setting
 * @pre pointer to space = 5 (point to space = 5) 
 * @post Output== 4
 */
void test1_space_get_north();
/**
 * @test Test function for space_get_NORTH setting
 * @pre pointer to space = NULL (point to space = NULL) 
 * @post Output== NO_ID
 */
void test2_space_get_north();
/**
 * @test Test function for space_get_south setting
 * @pre pointer to space = 5 (point to space = 5) 
 * @post Output== 2
 */
void test1_space_get_south();
/**
 * @test Test function for space_get_south setting
 * @pre pointer to space = NULL (point to space = NULL) 
 * @post Output== NO_ID
 */
void test2_space_get_south();
/**
 * @test Test function for space_get_east setting
 * @pre pointer to space = 5 (point to space = 5) 
 * @post Output== 1
 */
void test1_space_get_east();
/**
 * @test Test function for space_get_east setting
 * @pre pointer to space = NULL (point to space = NULL) 
 * @post Output== NO_ID
 */
void test2_space_get_east();
/**
 * @test Test function for space_get_WEST setting
 * @pre pointer to space = 5 (point to space = 5) 
 * @post Output== 6
 */
void test1_space_get_west();
/**
 * @test Test function for space_get_WEST setting
 * @pre pointer to space = NULL (point to space = NULL) 
 * @post Output== NO_ID
 */
void test2_space_get_west();
/**
 * @test Test function for space_get_object setting
 * @pre pointer to space = 1 (point to space = 1) 
 * @post Output== TRUE
 */
void test1_space_get_object();
/**
 * @test Test function for space_get_object setting
 * @pre pointer to space = NULL (point to space = NULL) 
 * @post Output== FALSE
 */
void test2_space_get_object();
/**
 * @test Test function for space_get_object setting
 * @pre pointer to space = NULL (point to space = NULL) 
 * @post Output== FALSE
 */
void test3_space_get_object();

/**
 * @test Test function for space_print setting
 * @pre pointer to space = 25 (point to space = OK) 
 * @post Output== OK
 */
void test1_space_print();
/**
 * @test Test function for space_print setting
 * @pre pointer to space = NULL (point to space = NULL) 
 * @post Output== ERROR
 */
void test2_space_print();

#endif
