#include <string>
#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std;
string addBinary(string a, string b) {
  int aLength = a.size();
  int bLength = b.size();
  size_t maxLength = max(aLength, bLength);
  size_t minLength = min(aLength, bLength);
  string result;
  result.reserve(maxLength + 1);
  int carrier = 0;
  char ch;
  for (int i = 1; i <= minLength; ++i) {
    ch = carrier + a[aLength - i]
        + b[bLength - i] - 0x30;
    if (ch >= '2') {
      ch -= 2;
      carrier = 1;
    }
    printf("insert char %c\n", ch);
    result.push_back(ch);
  }
  printf("alength %d\tblength %d\n", aLength, bLength);
  int diff = aLength - minLength;
  while (diff > 0) {
    ch = carrier + a[--diff];
    printf("alength insert char %c\n", ch);
    if (ch >= '2') {
      ch -= 2;
      carrier = 1;
    }
    result.push_back(ch);
  }
  diff = bLength - minLength;
  while (diff >= 0) {
    printf("blength insert char %c\n", ch);
    ch = carrier + b[--diff];
    if (ch >= '2') {
      ch -= 2;
      carrier = 1;
    }
    result.push_back(ch);
  }
  if (carrier) {
    result.push_back('1');
  }
  reverse(result.begin(), result.end());
  return result;
}
int main()
{
  string a = "1101";
  string b = "110";
  string c = addBinary(a, b);
  cout<< a<< "\t+\t"<< b <<"\t=\t"<<c<<endl;
}
