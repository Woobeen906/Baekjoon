/*
   백준 2751 수 정렬하기 문제
   기초 정렬
*/
#include <iostream>
#include <algorithm>
using namespace std;
#define MAX 1000001
int number[MAX];

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        number[i] = num;
    }
    sort(number, number + n);

    for (int i = 0; i < n; i++) {
        cout << number[i] << "\n";
    }
}