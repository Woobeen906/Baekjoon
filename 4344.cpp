/*
   ���� 4344�� ����� �Ѱ��� ����
   ù° �ٿ� �׽�Ʈ���̽��� �־�����
   ��° �ٺ��� �� �׽�Ʈ���̽����� �л� ���� ù ���� �־�����
   �̾ �л����� ������ �־����� (������ 0�̻� 100����)
   �� ���̽� ���� �� �پ� ����� �Ѵ� �л����� ������ 
   �ݿø��Ͽ� �Ҽ��� ��° �ڸ����� ���
*/
#include <iostream>
using namespace std;
int stu[1001];
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int c;
    cin >> c;
    for (int i = 1; i <= c; i++) {
        double n;//�л� ��
        cin >> n;
        int sum = 0;
        for (int j = 1; j <= n; j++) {
            cin >>stu[j];
            sum += stu[j];
        }

        double ave = sum / n;
        int cnt = 0;

        for (int k = 1; k <= n; k++) {
            if (stu[k] > ave) {
                cnt++;
                
            }
        }
        cout.setf(ios::fixed);
        cout.precision(3);
        double result = cnt * 100 / n;
        cout << result<<"%\n";
    }
}