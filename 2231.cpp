/*
  백준 2231 분해합 문제
*/
#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	int result = 0;

	for (int i = 1; i <= n; i++) {
		int temp = i;
		int sum = 0;
		for (int j = 1; j <= temp * 10; j *= 10) {
			sum += temp / j % 10;
		}
		if (sum + temp == n) {
			result = temp;
			break;
		}

	}
	cout << result;
}