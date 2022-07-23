/* Exercise #1.

Embedded Software Engineer - Ascent Vision Technologies Australia
Coded: Arun Thomas

In your text file write a function that reverses an array of ints:

void reverse(int* array, int numElements){

// your code here

}
Example input:
int a[6] = {3,6,8,1,4,6}
reverse(a, 6);
// should result in {6,4,1,8,6,3} */


#include <iostream>

void reverse(int* array, int numElements) {

    int tempReversed[numElements];

    for (int i = 0; i < numElements; i++)
    {
        tempReversed[((numElements-1) - i)] = array[i]; // Storing the integer values in reverse order temporally
    }

    for (int i = 0; i < numElements ; i++) // Moving reversed integers to the original array
    {
        array[i] = tempReversed[i];
    }
    return;
}

int main(void) {

    printf("Hello, AVT \n");
    int a[6] = {3,6,8,1,4,6};

    reverse(a,6);

    printf("Reversed array: ");
    for (int i = 0; i < 6; i++)
    {
        printf("%d ", a[i]);
    }
    return 0;
}



