/*
  백준 9465번 스티커 문제
*/
#include <iostream>
#include <algorithm>
using namespace std;
#define MAX 100001
int arr[2][MAX];
int dp[2][MAX];
int main() {
	int t;
	cin >> t;
	for (int T = 0; T < t; T++) {
		int n;
		cin >> n;
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < n; j++) {
				cin >> arr[i][j];
			}
		}
		dp[0][0] = arr[0][0];
		dp[1][0] = arr[1][0];
		for (int i = 1; i < n; i++) {
			dp[0][i] = max(max(dp[0][i - 1], dp[1][i - 1] + arr[0][i]), dp[0][i - 2] + arr[0][i]);
			dp[1][i] = max(max(dp[1][i - 1], dp[0][i - 1] + arr[1][i]), dp[1][i - 2] + arr[1][i]);
		}

		cout << max(dp[0][n - 1], dp[1][n - 1])<<"\n";
	}
}