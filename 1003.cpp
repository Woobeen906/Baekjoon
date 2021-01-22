#include <iostream>
using namespace std;
int cnt_0 = 0, cnt_1 = 0;
int dp_0[91];
int dp_1[91];

int fibonacci(int n) {
	if (n == 0) {
		//cout << "0";
		cnt_0++;
		return 0;
	}
	else if (n == 1) {
		//cout << "1";
		cnt_1++;
		return 1;
	}
	else {
		return fibonacci(n - 1) + fibonacci(n - 2);
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int T, n;
//	cin >> T;
//	for (int test_case = 1; test_case <= T; test_case++) {
		for(n=0;n<=40;n++){
	//	cin >> n;
		dp_0[0] = dp_1[1] = 1;
		dp_1[0] = dp_0[1] = 0;

		for (int i = 2; i <= n; i++) {
			dp_0[i] = dp_0[i - 1]+dp_0[i-2];
			dp_1[i] = dp_1[i - 1] + dp_1[i - 2];
		}
		fibonacci(n);
		cout << dp_0[n] << " " << dp_1[n]<<"\n";
		cout << cnt_0 << " " << cnt_1<<"\n";
		if (dp_0[n] == cnt_0 && dp_1[n] == cnt_1)cout << "True" << "\n";
		else cout << "false" << "\n";
		cnt_0 = cnt_1 = 0;
	}
}