/*
   ���� 11720�� ������ �� ����
   ������� ���ڰ� �־��� ��
   �� ���ڵ��� ���� ���
   string ������ a�� a[i]���·� ������ 
   a�� ���Ե��ִ� ���ڵ��� �ƽ�Ű�ڵ尪('1'�� ��� 49)�� int������ ��ȯ�� 
   sum�� �����ش�.
   a[i] -'0'�� ���ִ� ����
   ���� '0'�� �� ���� '1','2'...� ���̴�
   ���� ���� 0�� 1,2,3 �鿡 ���̿� ����

   ����(string �̳� char ��)�� �ƽ�Ű �ڵ尪(int��) ���� �ٲ� ���
   �� ��(0�̳� 1��)�� �״�� ��µ��� �ʰ� 49�� ���� ���� ��ȯ������
   '0'�� ���־� ��Ȯ�� int�� ���� ����Ѵ�.
*/
#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	string a;
	int n;
	int sum = 0;
	cin >> n;
	cin >> a;
	for (int i = 0; i < n; i++) {
		sum += a[i] - '0';
	}

	cout << sum;
}