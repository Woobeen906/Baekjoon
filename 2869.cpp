#include <iostream>
using namespace std;

int main() {
	double a, b, v;

	cin >> a >> b >> v;
	double result =(v - b) / (a - b);

	if (result - (int)((v - b) / (a - b)) != 0)cout << (int)((v - b) / (a - b)) + 1;
	else cout << (int)((v - b) / (a - b));

}