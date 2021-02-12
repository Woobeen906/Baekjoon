#include <iostream>
#include <queue>
using namespace std;

queue<int>q1;
queue<int>q2;
int main() {
	int n,k;
	cin >> n>>k;
	for (int i = 1; i <= n; i++)q1.push(i);

	int j = 0;
	while (!q1.empty())
	{
		j++;
		if (j % k == 0) {
			q2.push(q1.front());
			q1.pop();
		}
		else {
			q1.push(q1.front());
			q1.pop();
		}
	}
	cout << "<";
	for (int i = 0; i < n; i++) {
		cout << q2.front();
		q2.pop();
		if (i == n - 1)break;
		cout << ", ";
	}
		cout << ">";
}