#include <stdio.h>

#define N 10

void quicksort(int *low, int *high);

int main(void) {
  int a[N], i;

  // Prompts the user to enter 10 numbers to be sorted.
  printf("Enter %d numbers to be sorted\n", N);

  for (int i = 0; i < N; i++) {
    printf("%d: ", i + 1);
    scanf("%d", &a[i]);
  }

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
  int c = *a;
  *a = *b;
  *b = c;
}

// Splits an array of numbers down the middle.
int* split(int *low, int *high, int *middle) {
  int *i, *j;
  i = low;
  j = high;
  int p = *middle;

  while (j > middle) {
    while (p < *i)
      middle++;
    while (*j > *i)
      j--;
    if (j > middle) swap(middle,j);
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
  // Ends the function if there is only 1 number in the array. 
  if (low >= high) return;
  // Splits the array at roughly the center.
  int *middle = split(low, high, find_middle(low, high));
  // Quicksorts the left half of the array.
  quicksort(low, middle - 1);
  // Quicksorts the right half of the array.
  quicksort(middle + 1, high);
}