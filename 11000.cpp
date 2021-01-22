#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
#define MAX 200001
int n;
pair<int,int> pq[MAX];
priority_queue<int, vector<int>, greater<int> >q;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int s,t;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> s >> t;
		pq[i].first = s;
		pq[i].second = t;
	}

	sort(pq, pq + n);
	q.push(pq[0].second);
	for (int i = 1; i < n; i++) {
		if (q.top() <= pq[i].first) {
			q.pop();
			q.push(pq[i].second);
		}
		else {
			q.push(pq[i].second);
		}
	}
	cout << q.size();
}