/*−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−
Library of `Bubble Sort`

The intuitive idea is to iterate the list and bubble out the biggest 
element found to the end of the list, then finding the biggest element 
in the remaining list (excluding the last element) and sending it 
to the second last position and so on...

Practically, we start inner loop from `j=1` to `j=len-i` where i
simply increments by 1 with each iteration of outer loop; 
implying that with each iteration, the upper limit of the inner loop (of j) 
decreases by 1.

Since we are starting from `j=1` we compare the (j-1)th element with (j)th,
keeping the larger element on the right. The pair of `j-1` and `j` carries 
the largest one to the end.

`swapped` variable is just there to reduce the number of unnecessary loop iterations.
−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−*/

# include <stdio.h>

/* 
Swaps values of any two int variables provided the following parameters;
    - arr (int *)   : pointer to the array
    - i (int)       : index of the first variable in the array `arr`
    - j (int)       : index of the second variable in the array `arr`
*/ 
void swap(int *arr,int i,int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

/* 
Sorts an array in-place, using bubble sort algorithm provided the following parameters;
    - size (int)        : length of the array
    - arr[size] (int)   : array of length `size`
*/ 
void bsort_int(int size, int arr[size]) {
    int swapped = -1;
    for (int i = 0; i < size; i++) {
        swapped = 0;
        for (int j = 1; j < size-i; j++) {
            if (arr[j-1]>arr[j]) {
                swap(arr,j-1,j);
                swapped++;
            }        
        }       
        if (swapped==0) break;
    }
}

// Example case:
// int main() {
//     int arr[] = {100,-1,1,34,56,64,89};
//     bsort_int(7,arr);

//     for (int i=0;i<7;i++) 
//     printf(" %d",arr[i]);
// }