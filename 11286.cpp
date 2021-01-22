#include <iostream>
#include <queue>
#include <math.h>
using namespace std;


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int x, n;
	cin >> n;
	priority_queue<int, vector<int>, greater<int> >pq;
	priority_queue<int, vector<int>, less<int> >pq2;

	for (int i = 0; i < n; i++) {
		cin >> x;
		if (x == 0) {
			if (pq.empty()&&pq2.empty())cout << 0 << "\n";

			else if(!pq.empty()&&!pq2.empty()){
				if ( abs(pq.top()) > abs(pq2.top()) )
				{
						cout << pq2.top() << "\n";
						pq2.pop();
				}
				else if( abs(pq.top())<abs(pq2.top()) )
				{
					cout << pq.top() << "\n";
					pq.pop();
				}
				else {
					cout << pq2.top() << "\n";
					pq2.pop();
				}
			}

			else if (pq.empty()) {
				cout << pq2.top() << "\n";
				pq2.pop();
			}
			else if (pq2.empty()) {
				cout << pq.top() << "\n";
				pq.pop();
			}
		}

		else {
			if (x > 0)pq.push(x);
			if (x < 0)pq2.push(x);
		}
	}
}