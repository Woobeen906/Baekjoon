#include <iostream>


using namespace std;
char arr[64][64];

void dfs(int a, int b, int n) {
	int s = 0,i,j;
	char w = arr[a][b];
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			if (w != arr[a + i][b + j]) {
				s = 1;
				break;
			}}
		if (j != n) {

			break;
		}

	}

	if (s == 0)cout << w;
	else {
		cout << "(";
		n /= 2;
		dfs(a, b, n);
		dfs(a, b + n, n);
		dfs(a + n, b, n);
		dfs(a + n, b + n, n);
		cout << ")";
	}
}

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}
	dfs(0, 0, n);
}