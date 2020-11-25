/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   hash.h
 * Author: jakeeee
 *
 * Created on August 5, 2018, 2:34 PM
 */


#ifndef HASH_H
#define HASH_H

#ifdef __cplusplus
extern "C" {
#endif

    
#define NODATA 0
    typedef struct List {
        long unsigned int data = NODATA;
        struct List* next = NULL;
    } lst;
#ifdef __cplusplus
}
#endif

#endif /* HASH_H */

