#include <iostream> //It's cpp not c

#define N 10

// Prototypes matching your pointer-based engine
void quicksort(int *low, int *high);
void swap(int *a, int *b);
int* split(int *low, int *high);

int main(void) {
  int a[N]; 

  std::cout << "Enter " << N << " numbers to be sorted:\n";

  for (int i = 0; i < N; i++) {
    std::cin >> a[i];
  }
  

  quicksort(&a[0], &a[N - 1]);

  std::cout << "In sorted order: ";
  for (int i = 0; i < N; i++) {
    std::cout << a[i] << (i < N - 1 ? ", " : ""); 
  }
  std::cout << "\n";

  return 0;
}

void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

int* split(int *low, int *high) {
  int pivot = *low;
  int *i = low - 1;
  int *j = high + 1;

  while (1) {
    do { j--; } while (*j > pivot);
    do { i++; } while (*i < pivot);

    if (i >= j) return j;
    
    swap(i, j);
  }
}

void quicksort(int *low, int *high) {
  if (low >= high) return;

  int *middle = split(low, high);
  
  quicksort(low, middle);
  quicksort(middle + 1, high);
}
