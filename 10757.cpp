/*
  ���� 10757 ū �� ���ϱ� ����
  �� �� a,b�� ������ 0<a,b<1e10000 �̴�
  �̶� �� ���� ���� ���ϴ� ����
*/
#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string A, B,sum;
    cin >> A >> B;
    if (A.size() > B.size()) {
        string C;
        for (int i = 0; i < A.size() - B.size(); i++) C += '0';
            B = C + B;
        
    }
    else {
        string C;
        for (int i = 0; i < B.size() - A.size(); i++) C += '0';
            A = C + A;
        
    }
    int carry = 0; //�� ���� ���� 10�̻��� �� ����� �ø���

    while (A.size()!=0 && B.size()!=0) {
        int Aback = A.back() - '0';
        int Bback = B.back() - '0';
        int result = (carry + Aback + Bback)%10;//���� �ڸ���
        carry = (carry + Aback + Bback) / 10;//�ø���
        sum = (char)(result + '0') + sum;
        A.pop_back();
        B.pop_back();
    }
    if (carry) sum = (char)(carry + '0') + sum;
    
    cout<<sum;
    

}