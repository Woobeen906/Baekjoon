/* 
   백준 1712번 문제
   손익분기점을 측정하는 문제
   손익분기점이 없을시 -1을 출력

*/
#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	long long int a, b, c;
	//a= 고정비용 b=노트북 한대 생산 비용 c= 노트북 가격

	cin >> a >> b >> c;
	long long int break_even_point = a; //최초  손익 분기점
	long long int total_cost=0; //노트북 총 생산 비용

		if (b >= c) {
			cout << -1;
		}
		else {
			total_cost = a / (c - b);
			cout << total_cost + 1;
		}
}