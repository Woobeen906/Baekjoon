#include <iostream>
using namespace std;

int main() {
    string s;

    cin >> s;

    int reverse0 = 0,reverse1 = 0;

    if (s[0] == '0') reverse0++;
    else reverse1++;

    for (int i = 1; i < s.length(); i++) {
        if (s[i] != s[i - 1]) {
            if (s[i] == '1') reverse1++;
            else reverse0++;
        }
    }

    if (reverse1 > reverse0) cout << reverse0;
    else cout << reverse1;


}