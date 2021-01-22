/*
	골드바흐의 추측
*/
#include <iostream>0
using namespace std;
int num[1000001];

void init(int n) {
	for (int i = 0; i <= n; i++)num[i] = i;
}

void div(int n) {
	for (int i = 2; i * i <= n; i++) {
		for (int j = i * i; j <= n; j += i) {
			num[j] = -1;//서로소==-1
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	for (;;) {
		int n;
		cin >> n;
		init(n);
		div(n);
		if (n == 0)break;
		int cnt = 0;
		for (int i = 3; i <= n/2; i += 2) {
			if (num[i] != -1 && num[n - i] != -1) {
				cout << n << " = " << i << " + " << n - i << "\n";
				cnt = 1;
				break;
			}
			if (cnt == 1)break;
		}
		if (cnt == 0)cout << "Goldbach's conjecture is wrong." << "\n";

	}
}