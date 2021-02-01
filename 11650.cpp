#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(pair<int, int> a, pair<int, int> b) {
	if (a.first != b.first)return a.first < b.first;
	return a.second < b.second;
}

int main() {
	int n;
	cin >> n;
	vector<pair<int, int>> coordinates;
	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		coordinates.push_back({ x,y });
	}
	sort(coordinates.begin(), coordinates.end(), compare);
	
	for (int i = 0; i < n; i++) {
		cout << coordinates[i].first<<" "<<coordinates[i].second<<"\n";
	}
}