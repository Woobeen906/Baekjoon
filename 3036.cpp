#include <iostream>
#include <vector>
#include <algorithm> //binary_search(a,b,c); 0,1반환
#include <utility>
#include <queue>
#include <string.h>
//sort(v.begin(),v.end()); 오름차순
//sort(v.begin(),v.end(),greater<>()); 내림차순
using namespace std;
int a, b, n;
long long sum;
vector<int> v;

int gcd(int a, int b) {
	int c;
	if (a > b) {
		while (b != 0) {
			c = a % b;
			a = b;
			b = c;
		}
		return a;
	}
	else {
		while (a != 0) {
			c = b % a;
			b = a;
			a = c;
		}
		return b;
	}
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int num;
	int lcm = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> num;
		v.push_back(num);
	}
	for (int i = 1; i < n; i++) {
		int lcm1 = 0, lcm2 = 0;
		lcm = v[0] * v[i] / gcd(v[0], v[i]);
		lcm1 = lcm / v[i];
		lcm2 = lcm / v[0];
		cout << lcm1 << "/" << lcm2 << "\n";
	}
}