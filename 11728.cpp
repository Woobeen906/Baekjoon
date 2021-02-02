#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	int arr[200001] = { 0, };
	for (int i = 0; i < n+m; i++) {
		cin >> arr[i];
	}
	sort(arr, arr+(n+m));
	for (int i = 0; i < (n+m); i++)cout << arr[i] << " ";
}