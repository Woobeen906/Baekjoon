/*
  백준 1065번 한수 문제
*/
#include <iostream>
using namespace std;

int main() {
    int n, cnt = 0;
    cin >> n;
   if (n < 100)cnt = n;
   else {
       if (n == 1000)n = 999;
       for (int i = 100; i <= n; i++) {
           int a = i % 10;
           int b = i / 10 % 10;
           int c = i / 100 % 10;
           if ((a - b) == (b - c))cnt++;
       }
       cnt += 99;
   }
   cout << cnt;
}