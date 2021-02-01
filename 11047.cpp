#include <iostream>
using namespace std;

int main() {
	int n, k;
	cin >> n >> k;
	int coins[11],coinCnt=0;

	for (int i = 0; i < n; i++) {
		int coin;
		cin >> coin;
		coins[i] = coin;
	}
	for (int i = n - 1; i >= 0; i--) {
		if (k >= coins[i]) {
			coinCnt += k / coins[i];
			k = k % coins[i];
		}
	}
	cout << coinCnt;
}