/*
   백준 1152 단어의 개수 문제
   영어 대소문자와 띄어쓰기로 이루어진 문자열이 주어질 때
   문자열에 포함된 단어의 개수를 출력
*/

#include <iostream>
#include <string>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int cnt = 0;
    string a;
    getline(cin, a);
    if (a.length() >=2) {
        for (int i = 1; i < a.length() - 1; i++) {
            if (a[i] == ' ')cnt++;
        } cout << cnt+1;
    }
    else {
        if (a[0] == ' ');
        else {
            cnt++;
        }
        cout << cnt;
    }
   
}