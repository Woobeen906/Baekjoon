#include <iostream>
#include <stack>
using namespace std;

int main() {
	int n,num[500001];
	stack<int> s;
	stack<int> coordinate;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int number;
		cin >> number;
		num[i] = number;
	}

	s.push(num[0]);
	coordinate.push(1);
	cout << 0 << " ";
	for (int i = 1; i < n; i++) {
		if (num[i] <= s.top()) {
			cout << coordinate.top() << " ";
		}
		else {
			while (!s.empty()&&num[i]>s.top())
			{
				s.pop();
				coordinate.pop();
			}
			if (s.empty()) {
				cout << 0 << " ";
			}
			else if (num[i] <= s.top()) {
				cout << coordinate.top() << " ";
			}
		}
		s.push(num[i]);
		coordinate.push(i+1);
	}
}