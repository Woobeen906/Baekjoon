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
		q.push(num); //���� ����
	}

	long long x = 0;

	for (int i = 0; i < n; i++) {
		x = q.top(); //n��°�� ������ x���� n��° ���� �����̴�
		q.pop();
		for (int j = 0; j < k; j++) {
			long long sum = x*arr[j]; //�ʱ��� �Ҽ��� arr �� q�� �� �� ������ ���ϰ�
			q.push(sum); //q�� �ٽ� �ִ´�
			if (x % arr[j] == 0)break;
		}
	}
	cout << x;

}