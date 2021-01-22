#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define MAX 10001
int parent[MAX];

typedef struct ed {
	int start, end, weight;
};

vector<ed> vec;

bool compare(ed a,ed b) {
	return a.weight < b.weight;
}

int find(int a) {
	if (parent[a] == a)return a;
	return parent[a] = find(parent[a]);
}
void merge(int a, int b) {
	int ap = find(a);
	int bp = find(b);
	(ap < bp) ? parent[bp] = ap: parent[ap] = bp;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int v, e,sum=0;
	cin >> v >> e;
	for (int i = 1; i <= v; i++)parent[i] = i;//정점 초기화

	for (int i = 0; i < e; i++) {
		int a, b, c; //정점 a,b 와 가중치c
		cin >> a >> b >> c;
		vec.push_back({ a,b,c });
	}
	sort(vec.begin(), vec.end(), compare); //가중치가 작은순으로 정렬

	for (int i = 0; i < e; i++) {
		if (find(vec[i].start) == find(vec[i].end))continue; 
		else {
			merge(vec[i].start, vec[i].end);
			sum += vec[i].weight;
		}
	}
	cout << sum;

}