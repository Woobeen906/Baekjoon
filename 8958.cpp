/*
   백준 8958 ox퀴즈 문제
   "OOXXOXXOOO"와 같은 OX퀴즈의 결과가 있다. 
   O는 문제를 맞은 것이고, X는 문제를 틀린 것이다. 
   문제를 맞은 경우 그 문제의 점수는 그 문제까지 연속된 O의 개수가 된다.
   예를 들어, 10번 문제의 점수는 3이 된다.

   "OOXXOXXOOO"의 점수는 1+2+0+0+1+0+0+1+2+3 = 10점이다.

   OX퀴즈의 결과가 주어졌을 때, 점수를 구하는 프로그램
*/
#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int test_case;
    cin >> test_case;
    for (int T = 1; T <= test_case; T++) {
        string a;
        cin >> a;
        int sum = 0,cnt =0;
        for (int i = 0; i < a.length(); i++) {
            if (a[i] == 'O') {
                cnt++;
                sum += cnt;
            }
            else {
                cnt = 0;
            }
        }
        cout << sum << "\n";
    }

}