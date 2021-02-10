#include <iostream>
#include <algorithm>
using namespace std;
#define ll long long

ll arr[1000001];
ll tree[4000001];

ll sum(int node, int start, int end, ll left, ll right) {
	if (left > end || right < start)return 0;
	if (left <= start && end <= right)return tree[node];

	int mid = (start + end) / 2;
	return sum(node * 2, start, mid, left, right) + sum(node * 2 + 1, mid + 1, end, left, right);
}

void update(int node, int start, int end, ll index, ll diff) {
	if (!(start <= index && index <= end))return;

	tree[node] += diff;

	if (start != end) {
		int mid = (start + end) / 2;
		update(node * 2, start, mid, index, diff);
		update(node * 2 + 1, mid + 1, end, index, diff);
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n, m, a;
	ll b, c;
	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		if (a == 1) {
			update(1, 1, n, b, c - arr[b]);
			arr[b] = c;
		}
		else {
			if (b > c)swap(b,c); // c가 무조건 b보다 크다는 조건이 없음
			cout << sum(1, 1, n, b, c) << "\n";
		}
	}
}