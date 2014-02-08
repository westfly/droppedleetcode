#include "code_utils.h"
int firstElement(int A[], int n, int target) {
  int first = 0;
  int last = n;
  int middle  = 0;
  while (first < last) {
    middle = first + ((last - first)>>1);
    if (A[middle] < target) {
      first = middle + 1;
    } else {
      last = middle;
    }
  }
  return A[first]==target? first: -1;
}
int lastElement(int A[], int n, int target) {
  int first = 0;
  int last = n;
  int middle  = 0;
  while (first < last) {
    middle = first + ((last - first)>>1);
    if (A[middle] <= target) {
      first = middle + 1;
    } else {
      last = middle;
    }
  }
  return A[--last] == target? last: -1;
}
vector<int> searchRange(int A[], int n, int target) {
  vector<int> result;
  result.push_back(firstElement(A, n, target));
  result.push_back(lastElement(A, n, target));
  printf("%d\t%d\n", result[0],result[1]);
  return result;
}
int main()
{
  int array [] = {
    1, 2, 3, 5,5, 6,7,8
  };
  searchRange(array, ARRAY_SIZE_UNSAFE(array), 4);
}
