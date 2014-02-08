#include "code_utils.h"
int searchInsert(int A[], int n, int target) {
  int mid = 0;
  int first  = 0;
  int last = n;
  while (first < last) {
      // warning operator 
      mid = first + ((last - first) >> 1);
      printf("first = %d\t middle = %d\tlast = %d\n",
          first, mid, last);
      if (A[mid] < target) {
          first = mid + 1;
      } else if (A[mid] > target) {
          last = mid;
      } else {
          return mid;
      }
  }
  return first;
}
int main()
{
  int array [] = {
    1,3,5,6
  };
  int test_case [] = {
    5, 2, 7, 0
  };
  for(int i = 0; i < ARRAY_SIZE_UNSAFE(test_case); ++i) {
    int pos = searchInsert(array, ARRAY_SIZE_UNSAFE(array),
        test_case[i]);
    printf("%d\n", pos);
  }
}
