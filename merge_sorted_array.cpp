/* Exercise #2.

Embedded Software Engineer - Ascent Vision Technologies Australia
Coded: Arun Thomas

Write a function that efficiently merges two already sorted arrays (allows duplicates) into a new sorted array

int* mergeSortedArray(int* array1, int numElements1, int* array2, int numElements2){

// your code here

}

For example:
int a[4] = {1,4,6,8};
int b[6] = {3,5,5,6,9,10};
int* merged = mergeSortedArray(a, 4, b, 6);

// merged should contain {1,3,4,5,5,6,6,8,9,10} */


#include <iostream>


int* mergeSortedArray(int* array1, int numElements1, int* array2, int numElements2){

    // int newArray[(numElements1 + numElements2)];
    int* newArray = (int *) calloc((numElements1 + numElements2), sizeof(int));


    int j = 0;
    int k = 0;

    for (int i = 0; i < (numElements1 + numElements2); i++) // Loop to run through all the elements in the newArray.
    {
        if ((j < numElements1) && (k < numElements2)) // Checking if any of the array is overflowed. If not put the smallest item in the new array and increase the index.
        {
            if (array1[j] <= array2[k])
            {
                newArray[i] = array1[j];
                j++;
            }
            else
            {
                newArray[i] = array2[k];
                k++;
            }
        }
        else if (j < numElements1) // If any one of the array is overflowed then disregard that array and fill remaining of the new array with the other array.
        {
            newArray[i] = array1[j];
            j++;
        }
        else
        {
            newArray[i] = array2[k];
            k++;
        }
    }
    return newArray;
}


int main(void){

    printf("Hello, AVT \n");
    int a[4] = {1,4,6,8};
    int b[6] = {3,5,5,6,9,10};

    int* merged = mergeSortedArray(a, 4, b, 6);

    printf("Merged sorted array: \n");
    for (int i = 0; i < 10; i++)
    {
        printf("%d ", merged[i]);
    }

    free(merged);
    return 0;
}