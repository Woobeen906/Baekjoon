#include <iostream>
#include <queue>>
using namespace std;

priority_queue<int, vector<int> >min_q;
priority_queue<int, vector<int>, greater<int> >max_q;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n, num, mid = 1000000;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> num;
		if (num > mid)max_q.push(num); //num이 min_q보다 크면 max_q에 삽입
		else min_q.push(num); //반대일 경우 min_q에 삽입

		if (min_q.size() == max_q.size() - 1) {//max_q에 사이즈가 크면 max대신 min에 num을 삽입
			min_q.push(max_q.top());
			max_q.pop();
		}
		if (min_q.size() == max_q.size() + 2) {
			max_q.push(min_q.top());
			min_q.pop();
		}
		mid = min_q.top();
		cout << min_q.top() << "\n";
	}
}
