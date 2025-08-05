/*−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−
Library of `Completely Generic Functions`
−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−*/


// Standard Libraries

// #include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* 
Swaps values of any two compatible variables of any type provided the following parameters;
    - a (void *)    : pointer to the first variable
    - b (void *)    : pointer to the second variable
    - size (size_t) : size of the data type involved
Returns `0` if successful, else returns `-1`.
*/ 
int swap(void *a,void*b,size_t size) {
    if (!a || !b) return -1;

    void * temp = malloc(size);
    if (!temp) return -1;

    memcpy(temp,a,size);
    memcpy(a,b,size);
    memcpy(b,temp,size);
    return 0;
}