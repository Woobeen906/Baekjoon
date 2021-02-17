#include <iostream>
#include <algorithm>
using namespace std;
#define ll long long
#define MAX 1000000001
int arr[100002];
pair<int, int> tree[400001];

pair<int,int> init(int node, int s, int e) {
	if (s == e) {
		tree[node].first = arr[s];
		tree[node].second = arr[s];
		return tree[node];
	}
	int mid = (s + e) / 2;
	
	pair<int, int>left = init(node * 2, s, mid);
	pair<int, int>right = init(node * 2 + 1, mid + 1, e);
	tree[node].first = min(left.first,right.first);
	tree[node].second = max(left.second, right.second);
	return tree[node];
}

pair<int, int> sum(int node, int s, int e, ll left, ll right) {
	if (s > right || left > e)return { MAX,0 };
	if (s >= left && e <= right)return	tree[node];

	int mid = (s + e) / 2;

	pair<int, int> result;
	pair<int, int>left2= sum(node * 2, s, mid, left, right);
	pair<int, int>right2= sum(node * 2 + 1, mid + 1, e, left, right);
	result.first = min(left2.first, right2.first);
	result.second = max(left2.second, right2.second);

	return result;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)cin >> arr[i];

	init(1, 1, n);

	for (int i = 1; i <= m; i++) {
		int a, b;
		cin >> a >> b;
		pair<int, int> temp = sum(1, 1, n, a, b);
		cout <<temp.first << " " <<temp.second << "\n";
	}

}