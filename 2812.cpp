#include <iostream>
#include <stack>
using namespace std;

stack<char> s;
int main() {
	int n, k;
	string num;
	cin >> n >> k;
	cin >> num;
	for (int i = 0; i < n; i++) {
		while (k>0&&!s.empty()&&s.top()<num[i])
		{
			s.pop();
			k--;
		}
		s.push(num[i]);
	}
	stack<char>temp;
	
		while (k>0)
		{
			s.pop();
			k--;
		}
		while (!s.empty())
		{
			temp.push(s.top());
			s.pop();
		}
		while (!temp.empty())
		{
			cout << temp.top();
			temp.pop();
		}
}