#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

priority_queue<int ,vector<int>,greater<int> >q1;
priority_queue<int, vector<int> >q2;
int main() {
	int n,check=0,zero=0,one=0,num;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> num;
		if (num > 1)q1.push(num);
		if (num < 0)q2.push(num);
		if (num == 0)zero++;
		if (num == 1)one++;

	}
	int sum = 0, multiply=1;
	if (q1.size() % 2 == 1)q1.push(1);
	if (q2.size() % 2 == 1) {
		if (zero == 0)q2.push(1);
		else q2.push(0);
	}

	while (!q1.empty())
	{
		int num1 = q1.top();
		q1.pop();
		int num2 = q1.top();
		q1.pop();
		sum += num1*num2;
	}
	while (!q2.empty())
	{
		int num1 = q2.top();
		q2.pop();
		int num2 = q2.top();
		q2.pop();
		sum += num1 * num2;
	}



	cout << sum+one;
}