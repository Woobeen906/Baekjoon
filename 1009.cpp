#include <iostream>
using namespace std;

int main() {
	int T;
	cin >> T;
	for (int t = 0; t < T; t++) {
		int temp, a, b;
		cin >> a >> b;
		 temp= 1;

		while (b--)
		{
			temp = temp * a % 10;
		}
		if (temp == 0)cout << 10<<"\n";
		else
		cout << temp<<"\n";
	}
}