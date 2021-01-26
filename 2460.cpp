#include <iostream>
using namespace std;

int main() {
	int a, b, cnt = 0, max = 0;
	for (int i = 0; i < 10; i++) {
		cin >> a >> b;
		cnt -= a;
		cnt += b;
		if (cnt > max)max = cnt;
	}
	cout << max;
}