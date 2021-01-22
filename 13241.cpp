#include <iostream>
using namespace std;


long long gcd(int a, int b) {
	int c;
	if (a > b) {
		while (b != 0)
		{
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

long long lcm(long long a, long long b) {
	return a * b / gcd(a, b);
}


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	long long a, b;
	cin >> a >> b;
	cout << lcm(a, b);


}