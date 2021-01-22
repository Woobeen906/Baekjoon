#include <iostream>
using namespace std;

int arr[1001];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int N, K;
	cin >> N >> K;
	int cnt = 0;
	for (int i = 0; i <= N; i++) {
		arr[i] = -1;
	}

	for (int i = 2; i <= N; i++) {

		for (int j = i; j <= N; j += i) {
			if (arr[j] != -1)continue;
			else {
				cnt++;
				arr[j] = j;
			}
			if (cnt == K) {
				cout << arr[j];
				break;
			}
		}
	}
}