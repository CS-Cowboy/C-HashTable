/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Jacob Ziehli *
 * Created on August 3, 2018, 10:33 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "hash.h"

/*
 * 
 */
#define NUM_PRIMES 39

double sqrt(double);
void get_chain_end(lst *);

int main(int argc, char** argv) {
    uint primes [] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71,
        73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173}; /*For increasing the hashtable size... most likely overkill.*/
    ulong n = 0;

    if (argc != 2) {
        perror("You must provide an arg specifying the quantity of numbers to generate in to the hash table!\n");
    } else {
        n = atoi(argv[1]);
        ulong nearest_prime = 1;
        ulong m = sqrt(n);
        uint i = NUM_PRIMES;
        for (i; i > 0; i--) { //Count down from largest prime

            if (m > primes[i]) //If m is now greater than the current prime
            {
                nearest_prime = primes[i]; //Store and exit loop
                break;
            }
        } //At this point we have a prime number for sizing the 'lst' hash table.
        ulong len = sizeof (lst) * nearest_prime;
        lst *table = (lst*) malloc(len);
        printf("Putting %lu random ints in to linearly chained hash table using division method, with prime size: %lu\n", n, nearest_prime);
        srand(time(NULL));
        for (uint j = 0; j < n; j++) {
            uint data = (rand() % 100) + 1;
            uint index = data % nearest_prime;
            if (table[index].data == NODATA) {

                lst* temp = (lst*) malloc(sizeof (lst)); //Create a chain element
                temp->data = data;

                table[index] = *temp; //Connect these
            } else {
                lst *tmp = &table[index], prev;
                while (tmp->next != NULL) {
                    prev =*tmp;
                    tmp = tmp->next;
                }
                tmp->next = (lst*) malloc(sizeof (lst)); //Create a chain element
                tmp->data = data;
                prev.next = tmp; //Put it on the end
            }
        }

        for (ulong f = 0; f < nearest_prime; f++) {
            printf("Table[%lu]=  ", f);
            lst * tmp = &table[f];
            while (tmp != NULL) {
                printf("->%lu ", tmp->data);
                tmp = tmp->next;
            }
            printf("->[NULL].\n");
        }

    }
    return (EXIT_SUCCESS);
}

