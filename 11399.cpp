#include <iostream>
#include <algorithm>
using namespace std;
int people[1001];
int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)cin >> people[i];
	sort(people, people + n);

	int sum = 0;
	for (int i = 0; i < n; i++)sum += people[i] * n;

	for (int i = n - 1; i >= 0; i--) {
		sum -= people[i] * i;
	}
	cout << sum;
}