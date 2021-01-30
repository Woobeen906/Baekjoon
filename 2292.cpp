#include <iostream>
using namespace std;

int main() {
	long long n, j = 1;
	int cnt = 1, k = 1;
	cin >> n;
	if (n == 1)cout << 1;
	else {
		for (int i = 1;; i += 6) {
			j = j + (6 * k);
			k++;
			cnt++;
			if (i < n && n <= j)break;
		}
		cout << cnt;
	}
}