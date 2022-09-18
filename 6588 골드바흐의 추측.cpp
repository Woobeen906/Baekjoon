#include <iostream>
#include <cmath>
using namespace std;
#define MAX 1000001
int num[MAX];

void init() {
	for (int i = 0; i <= MAX; i++)num[i] = i;
}

void div() {
	for (int i = 2; i * i <= MAX; i++) {
		for (int j = 2 * i; j <= MAX; j += i) {
			num[j] = -1;//¼­·Î¼Ò==-1
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    init();
    div();
	for (;;) {
		int n;
		cin >> n;
		
		if (n == 0)break;
		int cnt = 0;
		for (int i = 3; i <= n; i += 2) {
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
