#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v;
vector<int> result;
int gcd(int a, int b) {
	int c;
		while (b != 0) {
			c = a % b;
			a = b;
			b = c;
		}
		return a;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,num;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> num;
		v.push_back(num);
	}
	sort(v.begin(), v.end());

	int divisor= v[1] - v[0];

	for (int i = 2; i < n; i++) {
		divisor = gcd(divisor, v[i] - v[i - 1]);
	}

	for (int i = 2; i*i<= divisor; i++) {
		if (divisor % i == 0) {
			result.push_back(i);
			result.push_back(divisor / i);
		}
	}

	result.push_back(divisor);
	sort(result.begin(), result.end());
	result.erase(unique(result.begin(), result.end()),result.end());

	for (int i = 0; i < result.size(); i++) {
		cout << result[i] << " ";
	}
}