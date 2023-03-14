/** 
 * @brief It implements the set module
 * 
 * @file set.c
 * @author Nicolás Ruiz
 * @version 2.0 
 * @date 02/03/2023
 * @copyright GNU Public License
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "set.h"


/**
 * @brief Set struct
 * 
 * This struct contains all the information of the set module
 */
struct _Set{
    Id *data;               /*Array de ids*/
    int n_ids;              /*Número de ids en el array*/
};



Set* set_create(){

    Set *newSet = NULL;

    newSet = (Set*) malloc(sizeof(Set));
    if(newSet == NULL){
        return NULL;
    }

    newSet->data = NULL;
    newSet->n_ids = 0;

    return newSet;
}



Set* set_destroy(Set *set){

    if(set == NULL){
        return NULL;
    }

    /*Si set->data tiene elementos => hacemos su free*/
    if (set->data != NULL){
        free(set->data);
    }

    free(set);

    return set;
}



STATUS set_add(Set *set, Id id){

    if(set == NULL || id == NO_ID){
        return ERROR;
    }

    set->n_ids++;
    set->data = realloc(set->data, sizeof(Id)*set->n_ids);

    /*Metemos el id dado en la última posición de la tabla*/
    set->data[set->n_ids-1] = id;

    return OK;
}



STATUS set_delete(Set *set, Id id){

    int i=0;

    if(set == NULL) {
        return ERROR;
    }

    /*Esto ya de por si comprueba si el set está vacío => set->n_ids = 0*/
    for(i=0; i<set->n_ids; i++){

        if(set->data[i] == id){
            set->data[i] = set->data[set->n_ids-1];
            set->n_ids--;
            return OK;
        }

    }
    return ERROR;
}


BOOL set_is_there(Set *set, Id id){

    int i=0;

    if(set == NULL || id == NO_ID){
        return FALSE;
    }

    for(i=0; i<set->n_ids; i++){
        if(set->data[i] == id){
            return TRUE;
        }
    }

    return FALSE;
}


BOOL set_empty (Set *set){

    if(set == NULL){
        return TRUE;
    }

    if(set->n_ids == 0){
        return TRUE;
    }

    return FALSE;
}


STATUS set_print(Set *set){

    int i=0;

    if(set == NULL){
        return ERROR;
    }

    if(set->n_ids == 0){
        fprintf(stdout, "Set contains no objects\n");
    }

    fprintf(stdout, "--> Set contains the following ids: \n");

    for(i=0; i<set->n_ids; i++){
        fprintf(stdout, "%d: %ld\n", i, set->data[i]);
    }

    return OK;
}