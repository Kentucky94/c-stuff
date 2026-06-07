#include "stdio.h"
#include "stdlib.h"

int main () {
    int a = 123;
    int b = 321;
    int *p = &a;
    int *q = &b;

    *p = *q;  // equal to a = b

    printf("hello: %d\n", a); // expect 321

    int arr_size = 20;
    int arr[arr_size];

    int *arr_start_ptr = arr;
    int *arr_4th_element_ptr = arr_start_ptr + 4;

    for (int i = 0; i < arr_size; i++) {
        arr[i] = i * i;
    }

    printf("Fourth el of array is: %d\n", arr[4]);
    printf("Fourth el of array by pointer is: %d\n", *arr_4th_element_ptr);
}