//Radix sort
#include <stdio.h>
#include <string.h>
#include <limits.h>
void printArray(int arr[], int len) {
  for (int i = 0; i < len; i++)
    printf("%d ", arr[i]);

  printf("\n");
}
void countingSort(int arr[], int N, int p) {
  int output[N];
  int count[10] = {0}; //keeping count if digits <=9

  for(int i = 0; i < N; i++)
    count[(arr[i] / p) % 10]++;

  //Applying counting sort so now the array contains actual position of the digits
  for(int i = 1; i < 10; i++) {
    count[i] += count[i - 1];
  }

  //staring from N-1 helps to keep digits in order
  for(int i = N - 1; i >= 0; i--) {
    output[count[(arr[i] / p) % 10] - 1] = arr[i];
    count[(arr[i] / p) % 10]--;
  }

  for(int i = 0; i < N; i++)
    arr[i] = output[i];
}
void radixsort(int arr[], int N) {
  int max = INT_MIN;

  for(int i = 0; i < N; i++) {
    if(arr[i] > max)
      max = arr[i];
  }

  int p = 1;
  int pass = 1;

  while(max / p > 0) {
    countingSort(arr, N, p);
    printf("After pass %d  : ", pass);
    printArray(arr, N);
    pass++;
    p *= 10;
  }
}
int main() {
  //Initializing array
  int arr[] = {9892, 49282, 12228, 903, 9011, 292829, 5291};
  int len = sizeof(arr) / sizeof(int);
  printf("Initial Array : ");
  printArray(arr, len);
  radixsort(arr, len);
  return 0;
}
