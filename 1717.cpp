#include <iostream>
using namespace std;
#define MAX 1000001
int parent[MAX];
int n, m;

int find(int a) { //a에 부모 값을 확인하는 함수
	if (parent[a] == a)return a;
	return parent[a] = find(parent[a]);
}

void merge(int a, int b) { //두 집합이 합집합인지 확인하는 함수
	int ap = find(a);
	int bp = find(b);
	(ap < bp) ? parent[bp] = ap : parent[ap] = bp;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int a,b, yn;
	cin >> n>>m;

	for (int i = 1; i <= n; i++) {
		parent[i] = i;
	}

	for (int i = 0; i < m; i++) {
		cin >> yn >> a >> b;
		if (yn == 0) {
			merge(a, b);
		}
		if (yn == 1) {
			if (find(a) == find(b)) {
				cout << "YES" << "\n";
			}
			else if(find(a)!=find(b)){
				cout << "NO" << "\n";
			}
		}
	}
}