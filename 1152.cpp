/*
   ���� 1152 �ܾ��� ���� ����
   ���� ��ҹ��ڿ� ����� �̷���� ���ڿ��� �־��� ��
   ���ڿ��� ���Ե� �ܾ��� ������ ���
*/

#include <iostream>
#include <string>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int cnt = 0;
    string a;
    getline(cin, a);
    if (a.length() >=2) {
        for (int i = 1; i < a.length() - 1; i++) {
            if (a[i] == ' ')cnt++;
        } cout << cnt+1;
    }
    else {
        if (a[0] == ' ');
        else {
            cnt++;
        }
        cout << cnt;
    }
   
}