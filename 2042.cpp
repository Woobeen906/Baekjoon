#include <iostream>
#include <math.h>
#include <vector>
using namespace std;
#define ll long long

ll arr[1000001];
ll tree[4000001];

ll init(int node, int start, int end) {
	if (start == end) return tree[node] = arr[start];


	int mid = (start + end) / 2;
	tree[node] = init(node * 2, start, mid) + init(node * 2 + 1, mid + 1, end);


	return tree[node];
}

ll sum(int node, int start, int end, ll left, ll right) {
	if (left > end || right < start)return 0;
	if (left <= start && end <= right)return tree[node];

	int mid = (start + end) / 2;
	return sum(node * 2, start, mid, left, right) + sum(node * 2 + 1, mid + 1, end,left, right);
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
	int n, m, k, a;
	ll b, c;
	cin >> n >> m >> k;

	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	init(1, 1, n);

	for (int i=0;i<m+k;i++) {
		cin >> a >> b >> c;
		if (a == 1) {
			update(1, 1, n, b, c - arr[b]);
			arr[b] = c;
		}
		else {
			cout<<sum(1, 1, n, b, c)<<"\n";
		}
	}
}