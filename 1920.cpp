#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int n, m;
	cin >> n;
	int A[100001],B[100001];
	for (int i = 0; i < n; i++)cin >> A[i];
	sort(A, A+n);

	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> B[i];
	}

	for (int i = 0; i < m; i++) {
		int left, right, mid;
		
		left = 0;
		right = n - 1;
		
		int result = 0;
		while (left<=right)
		{
			mid = (left + right) / 2;
			if (B[i] == A[mid]) {
				result = 1;
				break;
			}
			else if (B[i] > A[mid]) {
				left = mid + 1;
			}
			else if (B[i] < A[mid]) {
				right = mid - 1;
			}
		}
		cout << result << '\n';
	}
}