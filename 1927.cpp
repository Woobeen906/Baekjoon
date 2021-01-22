#include <iostream>
#include <queue>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	priority_queue<int,vector<int>,greater<int> >pq; //ÃÖ¼ÒÈüÀº greater
	int n, x;
	int cnt = 0;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> x;
		if (x == 0) {
			if (pq.empty())cout << 0 << "\n";
			else {
				cout << pq.top() << "\n";
				pq.pop();
			}
		}
		else if (x != 0) {
			pq.push(x);
		}
	}
}