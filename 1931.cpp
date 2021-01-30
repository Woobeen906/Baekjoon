#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<int, int>>v;

bool compare(pair<int, int>a, pair<int, int>b) {
	if (a.second== b.second)return a.first< b.first;
	else return a.second< b.second;
}

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		v.push_back({ a,b });
	}

	sort(v.begin(), v.end(), compare);
	int cnt = 1;
	int temp = 0, i = 0;
		for (int j = 1;j<v.size();j++) {
			if (v[j].first < v[i].second)continue;

			else {
				i = j;
				cnt++;
			}
		}
	cout << cnt;
}