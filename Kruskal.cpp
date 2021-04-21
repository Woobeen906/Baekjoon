#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define MAX 100001
int parent[MAX];
int n, m;

typedef struct  {
	int start;
	int end;
	int weight;
}ed;

vector<ed> v;

bool compare(ed& a, ed& b) {
	return a.weight < b.weight;
}

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
	int a, b, d;
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		parent[i] = i;
	}

	for (int i = 0; i < m; i++) {
		cin >> a >> b >> d;
		v.push_back({a,b,d});
	}

	sort(v.begin(), v.end(), compare);

	int sum = 0;

	for (int i = 0; i < m; i++) {
		if (find(v[i].start) == find(v[i].end))continue;
		else {
			merge(v[i].start, v[i].end);
			sum += v[i].weight;
		}
	}
	cout << sum;
}