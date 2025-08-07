#include <stdio.h>
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

    free(temp);
    return 0;
}

/*
Sorts an array according to bubble sort algorithm;
    - arr (void *)                      : pointer to the first variable
    - size (size_t)                     : size of the data type involved
    - len (size_t)                      : length of the array involved
    - compare (int (*)(void *, void *)) : comparator function
Returns a `void *` pointer to the sorted array.
*/
void* bsort(void *arr,size_t size, size_t len,int (*compare)(void *, void *)) {
    char * temp = (char *)malloc(size*len);
    memcpy(temp,arr,size*len);

    int swapped=-1;

    for (int i=0;i<len;i++) {
        swapped=0;
        for (int j=1 ; j<len-i ; j++) {
            if (compare(temp+(j-1)*size,temp+(j)*size)>0) {
                swap(temp+(j-1)*size,temp+j*size,size);
                swapped++;
            }     
        }

        if (swapped==0) break;
    }

    return (void *)temp;
}

// Example case
// int compare_int(void *a,void *b) {
//     return *(int *)a-*(int *)b;
// }

// int main() {
//     int arr[] = {12,34,1,-1,34,5,56};
//     size_t len = sizeof(arr)/sizeof(int);

//     int *final;
    
//     final = (int *)bsort(arr,sizeof(int),len,compare_int);

//     for (int i=0;i<len;i++) {
//         printf("%d ",final[i]);
//     }

//     return 0;
// }