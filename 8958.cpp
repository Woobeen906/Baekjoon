/*
   ���� 8958 ox���� ����
   "OOXXOXXOOO"�� ���� OX������ ����� �ִ�. 
   O�� ������ ���� ���̰�, X�� ������ Ʋ�� ���̴�. 
   ������ ���� ��� �� ������ ������ �� �������� ���ӵ� O�� ������ �ȴ�.
   ���� ���, 10�� ������ ������ 3�� �ȴ�.

   "OOXXOXXOOO"�� ������ 1+2+0+0+1+0+0+1+2+3 = 10���̴�.

   OX������ ����� �־����� ��, ������ ���ϴ� ���α׷�
*/
#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int test_case;
    cin >> test_case;
    for (int T = 1; T <= test_case; T++) {
        string a;
        cin >> a;
        int sum = 0,cnt =0;
        for (int i = 0; i < a.length(); i++) {
            if (a[i] == 'O') {
                cnt++;
                sum += cnt;
            }
            else {
                cnt = 0;
            }
        }
        cout << sum << "\n";
    }

}