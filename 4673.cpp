#include <iostream>
using namespace std;

int dnum(int a) {
	int cnt = 0;
	for (int i = 10;; i *= 10) {
		cnt++;
		if ((a / i )== 0 && (a % i) != 0) {
			break;
		}
	}

	int num = 10, sum = a;
	for (int j = 0; j < cnt;j++) {
		sum += (a %num * 10) / num;
		num *= 10;
	}

	return sum;
}

int main() {
	int selfnum[10001];
	for (int i = 0; i < 10001; i++)selfnum[i] = i;

	for (int i = 1; i < 10001; i++) {
		if(dnum(i)<10001)selfnum[dnum(i)]=-1;
	}

	for (int i = 1; i < 10001; i++) {
		if (selfnum[i] != -1)cout << selfnum[i] << '\n';
	}
}