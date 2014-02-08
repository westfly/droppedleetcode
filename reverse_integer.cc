int reverse_internal(int x);
int reverse(int x) {
  if (x < 0)
    return -reverse_internal(-x);
  else 
    return reverse_internal(x);
}
int reverse_internal(int x) {
  int sum = 0;
  while (x) {
    sum = sum*10 + (x%10);
    x /= 10;
  }
  return sum;
}
#include <cstdio>
int main()
{
  int x = 124;
  printf("%d\t reverse %d\n", x, reverse(x));
  x = -124;
  printf("%d\t reverse %d\n", x, reverse(x));
  return 0;
}
