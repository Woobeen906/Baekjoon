#include <iostream>
using namespace std;

int arr[10002];
int visit[10002];

void dfs(int start) {
	visit[start] = 1;

	if (visit[arr[start]] != 1)dfs(arr[start]);

}

int main() {
	int  T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		int n, cnt = 0;
		cin >> n;
		for (int i = 1; i <= n; i++) {
			int num;
			cin >> num;
			arr[i] = num;
		}

		for (int i = 1; i <= n; i++) {
			if (visit[i] != 1) {
				dfs(i);
				cnt++;
			}
		}

		cout << cnt << "\n";

		for (int i = 1; i <= n; i++) {
			arr[i] = 0;
			visit[i] = 0;
		}
	}
}