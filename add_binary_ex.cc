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
  int xst;
  char ch;
  while (aLength && bLength) {
    xst = carrier + a[--aLength]
        + b[--bLength] - 0x60;
    //carrier = xst/2;
    carrier = xst>>1;
    ch = (xst&0x1) + 0x30;
    //printf("insert char %c\n", ch);
    result.push_back(ch);
  }
  //printf("alength %d\tblength %d\n", aLength, bLength);
  while (aLength > 0) {
    xst = carrier + a[--aLength] - 0x30;
    carrier = xst>>1;
    ch = (xst&0x1) + 0x30;
    //printf("alength insert char %c\n", ch);
    result.push_back(ch);
  }
  while (bLength > 0) {
    ch = carrier + b[--bLength] - 0x30;
    carrier = xst>>1;
    ch = (xst&0x1) + 0x30;
    //printf("blength insert char %c\n", ch);
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
  string a = "110";
  string b = "110";
  string c = addBinary(a, b);
  cout<< a<< "\t+\t"<< b <<"\t=\t"<<c<<endl;
}
