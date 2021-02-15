#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n;
	long long m,max=0;
	vector<long long> trees;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		long long heigt;
		cin >> heigt;
		trees.push_back(heigt);
		if(max<heigt)max=heigt;
	}

	long long left=0, mid, right=max,result=0;
	while (left<=right)
	{
		mid = (left + right) / 2;
		long long sum = 0;
		for (int i = 0; i < n; i++) {
			if (mid < trees[i]) {
				sum += trees[i] - mid;
			}
		}

		if (sum >= m) {
			if (result < mid)result = mid;
			left = mid + 1;
		}
			else right = mid - 1;
		
	}
	cout << result;
}