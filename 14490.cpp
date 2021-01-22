#include <iostream>
using namespace std;

int gcd(int a, int b) {
	int c;

	if (a > b) {
		while (b != 0) {
			c = a % b;
			a = b;
			b = c;
		}
		return a;
	}
	else {
		while (a != 0) {
			c = b % a;
			b = a;
			a = c;
		}
		return b;
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n, m;
	char c;
	cin >> n >> c >> m;
	
	int GCD;
	GCD=gcd(n, m);
	cout << n / GCD << ":" << m / GCD;

}