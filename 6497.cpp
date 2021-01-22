#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define MAX 200001
int parent[MAX];
typedef struct {
	int start, end, weight;
}ed;

vector<ed> v;

bool compare(ed a, ed b) {
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
	for (;;) {
		int  m, n;//���Ǽ� m , ���Ǽ� n
		long long result = 0; //���û� ��� ���� ��
		long long sum = 0; //���û� ���� �Ÿ��� �ּ� ��
		cin >> m >> n;
		if (m == 0 &&n == 0)break;
		for (int i = 0; i < m; i++) {
			parent[i] = i;
		}

		for (int i = 0; i < n; i++) {
			int x, y, z;
			cin >> x >> y >> z;
			v.push_back({ x,y,z });
			result += z; 
		}
		sort(v.begin(), v.end(), compare);
		for (int i = 0; i < n; i++) {
			if (find(v[i].start) == find(v[i].end))continue;
			else {
				merge(v[i].start, v[i].end);
				sum+=v[i].weight;
			}
		}

		cout << result - sum<<"\n";//��� ���� �տ��� �ּҺ���� ���� ������ ����� ���´�
		v.clear();
	}
}
