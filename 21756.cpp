#include <iostream>
#include <queue>
using namespace std;


queue<int>q;

int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		q.push(i);
	}
	
	int cnt;
	while (q.size()>1)
	{
		cnt = 0;
		int n = q.size();
		while (cnt<n)
		{
			int temp = q.front();
			if (cnt % 2 == 0) {
				q.pop();
			}
			else {
				q.pop();
				q.push(temp);
			}
			cnt++;
		}
	}
	cout << q.front();
}