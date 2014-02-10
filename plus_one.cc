//http://oj.leetcode.com/problems/plus-one/
//Given a number represented as an array of digits, plus one to the number.
#include <vector>
#include <algorithm>
#include <iostream>
#include <iterator>
#include <stdio.h>

using namespace std;
vector<int> plusOne(vector<int> &digits) {
  vector<int> result; 
  result.reserve(digits.size() + 1);
  int carrier = 1;
  int xst = 0;
  // printf("size %d\t", result.size());
  for (auto iter = digits.rbegin(); 
      iter != digits.rend(); ++iter) {
    xst = *iter + carrier;
    carrier =  xst /10;
    result.push_back(xst %10);
  }
  if (carrier) {
    result.push_back(carrier);
  }
  reverse(result.begin(), result.end());
  return result;
}
int main() {
  int array [] = {
    0
  };
  vector<int> vtor(array, array + sizeof(array)/sizeof(array[0]));
  vector<int> nvtor = plusOne(vtor);
  copy(nvtor.begin(), nvtor.end(),
      ostream_iterator<int>(cout, " "));
}
