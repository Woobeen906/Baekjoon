#include <iostream>

using namespace std;

int main() {
	int T;
	cin >> T;
	for (int t = 0; t < T; t++) {
		int h, w, n;
		cin >> h >> w >> n;
		int cnt = 1;
		while (h<n)
		{
			cnt++;
			n -= h;
		}
		int result;

		result = n * 100 + cnt;
		cout << result << '\n';
	}
}