#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> v;

int main() {
	int n,num;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> num;
		v.push_back(num);
	}
	sort(v.begin(), v.end());

	if (v[0] != 1)cout << 1;
	else {
		int sum = 0;
		for (int i = 0; i < n; i++) {
			if (v[i] > sum + 1)break;
			sum += v[i];
		}
		cout << sum + 1;
	}
}