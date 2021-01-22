/*
    에라토스테네스의 체
    1. 2부터 N까지의 모든 정수를 적는다.
    2. 아직 지우지 않은 수 중 가장 작은 수를 찾는다. 이 수는 소수이다.
    3. 이 소수를 지우고 아직 지우지 않은 이 소수의 배수를 모두 지운다
    4. 이 과정을 반복한다.

*/
#include <iostream>
using namespace std;
int arr[1000002];
int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,m,num,cnt=0;
    cin >> m>>n;

    for (int i = 2; i <=n; i++) {
        arr[i] = 1;
    }
    for (int i = 2; i <= n; i++) {
        for (int j = i + i; j <= n; j += i)arr[j] = 0;
    }
    for (int i = m; i <= n; i++)if (arr[i] == 1)cout << i<<"\n";
}