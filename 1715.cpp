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
		q.push(num);//ī�忡 ���� q�� ����
	}
	for (;;) {
		if (q.size() == 1) { //2��. ����ؼ� ���� �� q�� ���� �ϳ� ������ res�� ���� ���� ���� �ȴ�
			cout << res;
			break;
		}
		if (q.size()!=1) { //1��. q�� ���� �ΰ� �̻��� ��� ���� ���� �� �ΰ��� ���Ѵ�
			sum = 0; 
			sum += q.top();
			q.pop();
			sum += q.top(); //�� ���� sum�� �ְ� �� ���� q�� ���� (���� �� ���� ���Ž�Ų��)
			q.pop();
			q.push(sum); //���� ���� �ٽ� ���� ���� ���ؾ� �ϱ⶧���� q�� ����
			res += sum; // ���� ���� ���� ���� ���̱⿡ res�� ����
		}
	}
}