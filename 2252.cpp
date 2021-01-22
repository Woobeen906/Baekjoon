#include <iostream>
#include <queue>
#include <vector>
using namespace std;
#define MAX 32001
priority_queue<int, vector<int>, greater<int> >q;
vector<int> v[MAX];
int degree[MAX];
int result[MAX];
int n, m;

void compare() {

	for (int i = 1; i <= n; i++) {
		if (degree[i] == 0)q.push(i);
	}

	for (int i = 1; i <= n; i++) {
		if (q.empty())return;

		int x = q.top();
		q.pop();
		cout << x << " ";
		result[i] = x;
		for (int i = 0; i < v[x].size(); i++) {
			int y = v[x][i];
			if (--degree[y] == 0)q.push(y);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int num1, num2;
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		cin >> num1 >> num2;
		v[num1].push_back(num2);
		degree[num2]++;
	}
	compare();
}