#include <iostream>
#include <stack>
using namespace std;

stack<int> s;

int main() {
	int n,num;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> num;
		if (num == 0)s.pop();
		else s.push(num);
	}
	int sum = 0;
	while (!s.empty())
	{
		sum += s.top();
		s.pop();
	}
	cout << sum;
}