#include <iostream>
using namespace std;

int main() {
	int money, cnt = 0, coin[] = {500,100,50,10,5,1};
	cin >> money;
	money = 1000 - money;
	for (int i = 0; i < 6; i++) {
		if (money / coin[i] != 0) {
			cnt += money / coin[i];
			money = money % coin[i];
		}
	}
	cout << cnt;
}