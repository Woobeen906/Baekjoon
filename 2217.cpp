#include <iostream>
#include <algorithm>

using namespace std;

int rope[100001];
int main() {
	int n, k, w;
	cin >> n;
	for (int i = 0; i < n; i++)cin >> rope[i];
	sort(rope, rope + n);
	int sum = 0, max = 0;
	for (int i = 0; i < n; i++) {
		sum = rope[i] * (n - i);
		if (sum > max)max = sum;
	}

	cout << max;
}