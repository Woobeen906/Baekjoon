/*
   문제 1로만들기

   정수 X에 사용할 수 있는 연산은 다음과 같이 세 가지 이다.

  1.  X가 3으로 나누어 떨어지면, 3으로 나눈다.
  2.  X가 2로 나누어 떨어지면, 2로 나눈다.
  3.  1을 뺀다.
   정수 N이 주어졌을 때,
   위와 같은 연산 세 개를 적절히 사용해서 1을 만들려고 한다. 연산을 사용하는 횟수의 최솟값을 구하는 문제
*/

#include <iostream>
#include <algorithm>
using namespace std;


int dp[1000001];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    
    int N;
	cin >> N; // 정수 N이 주어진다
   dp[1] = dp[2]=dp[3]=1 ;
    for (int i = 4; i <=N; i++) {
        dp[i] = dp[i - 1] + 1;
        if (i % 2 == 0)dp[i] = min(dp[i], dp[i / 2]+1);
        if (i % 3 == 0)dp[i] = min(dp[i], dp[i / 3]+1);

    }
    cout << dp[N];

}