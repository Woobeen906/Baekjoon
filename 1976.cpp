#include <iostream>
using namespace std;
#define MAX 1001
int parent[MAX];
int n, m;
int arr[201][201];
int arr2[MAX];

int find(int a) {
	if (parent[a] == a)return a;
	return parent[a] = find(parent[a]);
}

void merge(int a, int b) {
	int ap = find(a);
	int bp = find(b);
	(ap < bp) ? parent[bp] = ap : parent[ap] = bp;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	int yn, num;

	for (int i = 1; i <= n; i++) {
		parent[i] = i;
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> num;
			arr[i][j] = num;
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (arr[i][j] == 1)merge(i + 1, j + 1);
			else continue;
		}
	}

	for (int i = 0; i < m; i++) {
		cin >> yn;
		arr2[i] = yn;
	}
	for (int i = 0;; i++) {
		if (arr2[i + 1] == 0) {
			cout << "YES";
			break;
		}
		else {
			if (find(arr2[i]) == find(arr2[i + 1]))continue;
			else {
				cout << "NO";
				break;
			}
		}
	}
}