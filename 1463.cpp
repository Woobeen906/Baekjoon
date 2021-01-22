/*
   ���� 1�θ����

   ���� X�� ����� �� �ִ� ������ ������ ���� �� ���� �̴�.

  1.  X�� 3���� ������ ��������, 3���� ������.
  2.  X�� 2�� ������ ��������, 2�� ������.
  3.  1�� ����.
   ���� N�� �־����� ��,
   ���� ���� ���� �� ���� ������ ����ؼ� 1�� ������� �Ѵ�. ������ ����ϴ� Ƚ���� �ּڰ��� ���ϴ� ����
*/

#include <iostream>
#include <algorithm>
using namespace std;


int dp[1000001];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    
    int N;
	cin >> N; // ���� N�� �־�����
   dp[1] = dp[2]=dp[3]=1 ;
    for (int i = 4; i <=N; i++) {
        dp[i] = dp[i - 1] + 1;
        if (i % 2 == 0)dp[i] = min(dp[i], dp[i / 2]+1);
        if (i % 3 == 0)dp[i] = min(dp[i], dp[i / 3]+1);

    }
    cout << dp[N];

}