#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n, m;
	cin >> n >> m;
	int arr[2000001] = { 0, };
	for (int i = 0; i < n+m; i++) {
		cin >> arr[i];
	}
	sort(arr, arr+(n+m));
	for (int i = 0; i < (n+m); i++)cout << arr[i] << " ";
}