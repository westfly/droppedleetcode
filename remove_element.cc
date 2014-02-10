/*
 * http://oj.leetcode.com/problems/remove-element/
 * Given an array and a value, remove all instances of that value in place and return the new length.
 * The order of elements can be changed. It doesn't matter what you leave beyond the new length. 
 */
#include <algorithm>
#include <stdio.h>
int removeElement(int A[], int n, int elem) {
  if (n <=0) {
    return n;
  }
  int* pBegin = A;
  int* pLast = A + n;
  while (pBegin < pLast) {
    while ((pBegin < pLast) &&(*pBegin != elem)) {
      ++pBegin;
    }
    while ((pBegin < pLast)&& (*(pLast - 1) == elem)) {
      --pLast;
    }
    printf("first = (%d)\t last = (%d)\n",
        (pBegin - A), (pLast - A));
    if (pBegin < pLast)
      std::iter_swap(pBegin, --pLast);
    printf("first_element = (%d)\t last_element = (%d)\n",
        (*pBegin), *(pLast - 1));
  }
  return pLast - A;
}
void printArray(int A[], int n) {
  for(int i = 0; i < n; ++i) {
    printf("%d\t", A[i]);
  }
  //printf("\n");
  putchar('\n');
}
int main() {
  int array [] = {
    //1, 3, 5, 4, 5,2,6
    // 3,3
    5,5,3
  };
  printArray(array, sizeof(array)/sizeof(array[0]));
  int length = removeElement(array, sizeof(array)/sizeof(array[0]), 5);
  printArray(array, length);
  return 0;
}
