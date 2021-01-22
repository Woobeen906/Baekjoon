/*
  백준 10757 큰 수 더하기 문제
  두 수 a,b에 범위는 0<a,b<1e10000 이다
  이때 두 수의 합을 더하는 문제
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
    int carry = 0; //두 수를 더해 10이상일 때 생기는 올림수

    while (A.size()!=0 && B.size()!=0) {
        int Aback = A.back() - '0';
        int Bback = B.back() - '0';
        int result = (carry + Aback + Bback)%10;//남는 자릿수
        carry = (carry + Aback + Bback) / 10;//올림수
        sum = (char)(result + '0') + sum;
        A.pop_back();
        B.pop_back();
    }
    if (carry) sum = (char)(carry + '0') + sum;
    
    cout<<sum;
    

}