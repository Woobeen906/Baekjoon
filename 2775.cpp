#include <iostream>
using namespace std;
int home[15][15];


int main() {
	int k, n, T;
	cin >> T;
	for (int i = 0; i < 15; i++) {
		home[0][i] = i + 1;
		home[i][0] = 1;
	}

	for (int i = 1; i < 15; i++) {
		for (int j = 1; j < 15; j++) {
			home[i][j] = home[i - 1][j] + home[i][j - 1];
		}
	}

	for (int t = 0; t < T; t++) {
		cin >> k >> n;

		cout << home[k][n-1] << "\n";
	}
}