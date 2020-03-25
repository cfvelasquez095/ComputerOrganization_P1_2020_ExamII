#include <stdio.h>

int arr1[] = {7, 5, 3, 4, 6, 9}; // (size = 6) (minimum = 2)
int arr2[] = {4, 4, 4, 4, 4, 4}; // (size = 6) (minimum = 0)
int arr3[] = {9, 7, 5, 3, 2, 1}; // (size = 6) (minimum = 5)
int arr4[] = {1, 2, 3, 5, 7, 9}; // (size = 6) (minimum = 0)
int arr5[] = {9, 7}; //(size = 2) (minimum = 1)
int arr6[] = {7, 9}; //(size = 2) (minimum = 0)

#define ARRAY_SIZE(arr) (sizeof(arr)/sizeof(arr[0]))

int find_minimum(const int v[], int size)
{
    if (size == 0) {
        return -1;
    } else if (size == 1) {
        return 0;
    }
    int i = 0;
    
    while (i < (size - 1) && (v[i+1] < v[i])) {
        i++;
    }
    return i;
}

void test(int arr[], int size)
{
    int min = find_minimum(arr, size);
    printf("%d\n", min);
}

int main()
{
    test(arr1, ARRAY_SIZE(arr1));
    test(arr2, ARRAY_SIZE(arr2));
    test(arr3, ARRAY_SIZE(arr3));
    test(arr4, ARRAY_SIZE(arr4));
    test(arr5, ARRAY_SIZE(arr5));
    test(arr6, ARRAY_SIZE(arr6));
}
