#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main() {

	int n;
	vector <int> v;
	vector<int> v2;
	stack <int> s;

	cin >> n;

	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		v.push_back(num);
		v2.push_back(-1);
	}

	for (int i = 0; i < v.size(); i++) {
		while (!s.empty() && v[s.top()] < v[i]) {
			v2[s.top()] = v[i];
			s.pop();
		}
		s.push(i);
	}

	for (int i = 0; i < v2.size(); i++)cout << v2[i] << " ";
}