#include <iostream>
using namespace std;

int main() {
	int a, b;
	cin >> a >> b;
	int aa, bb;
	aa = a / 100 + a % 100 / 10 * 10 + a % 10 * 100;
	bb = b / 100 + b % 100 / 10 * 10 + b % 10 * 100;
	if (aa > bb)cout << aa;
	else cout << bb;
}