#include <iostream>
#include <queue>
using namespace std;
#define MAX 100000
int arr[MAX];

priority_queue<int, vector<int>, greater<int> >q; 
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int k, n, num;
	cin >> k>>n;

	for (int i = 0; i < k; i++) {
		cin >> num;
		arr[i] = num;
		q.push(num); //값을 삽입
	}

	long long x = 0;

	for (int i = 0; i < n; i++) {
		x = q.top(); //n번째로 나오는 x값이 n번째 값이 정답이다
		q.pop();
		for (int j = 0; j < k; j++) {
			long long sum = x*arr[j]; //초기의 소수들 arr 과 q에 맨 앞 값들을 곱하고
			q.push(sum); //q에 다시 넣는다
			if (x % arr[j] == 0)break;
		}
	}
	cout << x;

}