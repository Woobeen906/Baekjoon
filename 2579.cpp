#include <iostream>
#include <algorithm>
using namespace std;
int dp[301];
int visit[301];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> dp[i];
	}
	visit[0] = dp[0];
	visit[1] = max((dp[0] + dp[1]), dp[1]);
	visit[2] = max((dp[0] + dp[2]), (dp[1] + dp[2]));
	for (int i = 3; i < n; i++) {
		visit[i] = max(visit[i - 2] + dp[i], visit[i - 3] + dp[i - 1] + dp[i]);
	}
	cout << visit[n - 1];
}