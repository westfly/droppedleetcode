#include "code_utils.h"
int firstElement(int A[], int n, int target) {
  int* low = lower_bound(A, A+n, target); 
  return *low == target? low-A: -1;
}
int lastElement(int A[], int n, int target) {
  int* up = upper_bound(A, A+n, target); 
  return *up == target? up-A: -1;
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
