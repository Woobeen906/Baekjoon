/* 
   ���� 1712�� ����
   ���ͺб����� �����ϴ� ����
   ���ͺб����� ������ -1�� ���

*/
#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	long long int a, b, c;
	//a= ������� b=��Ʈ�� �Ѵ� ���� ��� c= ��Ʈ�� ����

	cin >> a >> b >> c;
	long long int break_even_point = a; //����  ���� �б���
	long long int total_cost=0; //��Ʈ�� �� ���� ���

		if (b >= c) {
			cout << -1;
		}
		else {
			total_cost = a / (c - b);
			cout << total_cost + 1;
		}
}