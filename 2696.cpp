/*
  백준 2696번 중앙값 구하기 문제
*/
#include <iostream>
#include <queue>
using namespace std;

priority_queue<int, vector<int> >smallQueue;
priority_queue<int, vector<int>, greater<int> >bigQueue;
vector<int> midValue;
int m;

void init() {
	while (!smallQueue.empty()) {
		smallQueue.pop();
	}
	while (!bigQueue.empty()) {
		bigQueue.pop();
	}
	while (!midValue.empty()) {
		midValue.pop_back();
	}
}

int main() {
	int T;
	cin >> T;
	for (int test_case = 1; test_case <= T; test_case++) {
		cin >> m;
		int mid = 999999;
		for (int i = 1; i <= m; i++) {
			int num;
			cin >> num;

			if (num > mid)bigQueue.push(num);
			else smallQueue.push(num);

			if (smallQueue.size() == bigQueue.size() - 1) {
				smallQueue.push(bigQueue.top());
				bigQueue.pop();
			}
			if (smallQueue.size() == bigQueue.size() + 2) {
				bigQueue.push(smallQueue.top());
				smallQueue.pop();
			}

			mid = smallQueue.top();

			if (i % 2 == 1)midValue.push_back(mid);
			else continue;
			
		}
		cout << midValue.size() << "\n";
		for (int a = 0; a < midValue.size(); a++) {
			if (a>9&&a % 10 == 0)cout << "\n";
			cout << midValue[a]<<" ";
		}
		init();
		cout << "\n";
	}
}