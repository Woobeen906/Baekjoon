#include <iostream>
#include <algorithm>
using namespace std;

char game[51][51];
int main() {

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string a;
		cin >> a;
		for (int j = 0; j < n; j++) {
			game[i][j] = a[j];
		}
	}

	int cnt = 0, result = 0;

	for (int i = 0; i < n; i++) {
		char point = game[i][0];
		for (int j = 0; j < n - 1; j++) {
			if (point == game[i][j + 1])cnt++;
			else {
				result = max(result, cnt);
				cnt = 0;
				point = game[i][j + 1];
			}
		}
		result = max(result, cnt);
		cnt = 0;
	}

	for (int i = 0; i < n ; i++) {
		char point = game[0][i];
		for (int j = 0; j < n - 1; j++) {
			if (point == game[j+1][i])cnt++;
			else {
				result = max(result, cnt);
				cnt = 0;
				point = game[j+1][i];
			}
		}
		result = max(result, cnt);
		cnt = 0;
	}
	
	cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n - 1; j++) {
			if (game[i][j] != game[i][j + 1]) {
				char temp = game[i][j];
				game[i][j] = game[i][j + 1];
				game[i][j + 1] = temp;
				char point = game[0][j];
				result = max(result, cnt);
				cnt = 0;
				for (int k = 0; k < n - 1; k++) {

					if (point == game[k + 1][j]) {
						cnt++;
					}
					else {
						result = max(result, cnt);
						cnt = 0;
						point = game[k + 1][j];
					}
				}
				result = max(result, cnt);
				cnt = 0;
				point = game[0][j + 1];
				for (int k = 0; k < n - 1; k++) {
					if (point == game[k + 1][j + 1]) {
						cnt++;
					}
					else {
						result = max(result, cnt);
						cnt = 0;
						point = game[k + 1][j + 1];
					}
				}
				result = max(result, cnt);
				cnt = 0;
				point = game[i][0];
				for (int k = 0; k < n - 1; k++) {
					if (point == game[i][k + 1]) {
						cnt++;
					}
					else {
						result = max(result, cnt);
						cnt = 0;
						point = game[i][k + 1];
					}
				}
				result = max(result, cnt);
				cnt = 0;
				temp = game[i][j];
				game[i][j] = game[i][j + 1];
				game[i][j + 1] = temp;
			}

		}
	}
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n; j++) {

			if (game[i][j] != game[i + 1][j]) {
				char temp = game[i + 1][j];
				game[i + 1][j] = game[i][j];
				game[i][j] = temp;
				char point = game[i][0];
				result = max(result, cnt);
				cnt = 0;
				for (int k = 0; k < n - 1; k++) {

					if (point == game[i][k + 1]) {
						cnt++;
					}
					else {
						result = max(result, cnt);
						cnt = 0;
						point = game[i][k + 1];
					}
				}
				result = max(result, cnt);
				cnt = 0;
				point = game[i + 1][0];
				for (int k = 0; k < n - 1; k++) {
					if (point == game[i + 1][k + 1]) {
						cnt++;
					}
					else {
						result = max(result, cnt);
						cnt = 0;
						point = game[i + 1][k + 1];
					}
				}
				result = max(result, cnt);
				cnt = 0;
				point = game[0][j];
				for (int k = 0; k < n - 1; k++) {
					if (point == game[k + 1][j]) {
						cnt++;
					}
					else {
						result = max(result, cnt);
						cnt = 0;
						point = game[k + 1][j];
					}
				}
				result = max(result, cnt);
				cnt = 0;
				temp = game[i + 1][j];
				game[i + 1][j] = game[i][j];
				game[i][j] = temp;
			}
		}
	}



	cout << result + 1;

}