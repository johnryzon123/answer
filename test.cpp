#include <stdio.h>

#define N 10

void quicksort(int *low, int *high);

int main(void) {
  int a[N], i;

  // Prompts the user to enter 10 numbers to be sorted.
  printf("Enter %d numbers to be sorted: ", N);

  for (int i = 0; i < N; i++)
    scanf("%d", &a[i]);

  int *low, *high;
  low = &a[0];
  high = &a[N-1];

  // Sorts the entered numbers.
  quicksort(low, high);

  // Prints the sorted numbers.
  printf("In sorted order: ");
  for (i = 0; i < N; i++)
    printf("%d, ", a[i]);
  printf("\n");

  return 0;
}

// Swaps two numbers
void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

// Splits an array of numbers down the middle.
int* split(int *low, int *high) {
    int pivot = *low;
    int *i = low;
    int *j = high;

    while (1) {
        while (*j > pivot && i < j) j--;
        while (*i <= pivot && i < j) i++;

        if (i >= j) break;
        swap(i, j);
    }
    
    swap(low, j);
    return j;
}

// Finds the middle element of an array. 
int* find_middle(int *left, int *right) {
  return &left[(right-left)/2];
}

// Sorts an array of numbers from lowest to highest. 
void quicksort(int *low, int *high) {
    if (low >= high) return;

    int *middle = split(low, high);
    quicksort(low, middle - 1);
    quicksort(middle + 1, high);
}