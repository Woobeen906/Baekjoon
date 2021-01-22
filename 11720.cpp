/*
   백준 11720번 숫자의 합 문제
   공백없이 숫자가 주어질 때
   그 숫자들의 합을 출력
   string 형태의 a를 a[i]형태로 나누어 
   a에 삽입돼있는 숫자들의 아스키코드값('1'에 경우 49)을 int형으로 변환후 
   sum에 더해준다.
   a[i] -'0'을 해주는 이유
   문자 '0'에 과 문자 '1','2'...등에 차이는
   실제 숫자 0과 1,2,3 들에 차이와 같다

   문자(string 이나 char 형)를 아스키 코드값(int형) 으로 바꿀 경우
   그 값(0이나 1등)이 그대로 출력되지 않고 49와 같은 값이 반환됨으로
   '0'을 빼주어 정확한 int형 값을 출력한다.
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