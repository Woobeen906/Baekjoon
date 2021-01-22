#include <iostream>
using namespace std;

int GCD(int a, int b) {
	int c;
	while (b != 0) {
		c = a % b;
		a = b;
		b = c;
	}
	return a;
}

int LCM(int a, int b) {
	return a * b / GCD(a, b);
}


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int gcd, lcm;
	cin >> gcd >> lcm;
	int gcd_result, lcm_result;
	
	lcm /= gcd;

	for (int i = 1; i*i <= lcm; i ++) {
		if (lcm % i == 0) {
			if (GCD(i, lcm / i) == 1) {
				gcd_result = gcd * i;
				lcm_result = lcm/i * gcd;
			}
		}
	}
	cout << gcd_result << " " << lcm_result;
}