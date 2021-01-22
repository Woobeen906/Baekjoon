#include <iostream>
#include <queue>
using namespace std;

priority_queue<int, vector<int>, greater<int> >q;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n, num, sum, res = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> num;
		q.push(num);//카드에 값을 q에 삽입
	}
	for (;;) {
		if (q.size() == 1) { //2번. 계속해서 더한 후 q에 값이 하나 남으면 res에 더한 값이 답이 된다
			cout << res;
			break;
		}
		if (q.size()!=1) { //1번. q에 값이 두개 이상일 경우 가장 작은 수 두개를 더한다
			sum = 0; 
			sum += q.top();
			q.pop();
			sum += q.top(); //두 수를 sum에 넣고 그 수를 q에 삽입 (더한 두 수는 제거시킨다)
			q.pop();
			q.push(sum); //더한 수를 다시 작은 수와 더해야 하기때문에 q에 삽입
			res += sum; // 더한 수를 합한 것이 답이기에 res에 삽입
		}
	}
}