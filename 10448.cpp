#include <iostream>
#include <vector>
#include <algorithm> //binary_search(a,b,c); 0,1반환
using namespace std;

int main() {
	int count = 0;
	int n;
	cin >> n;

	for (int z = 0; z < n; z++) {
		vector<int> v;

		int num;
		cin >> num;
		for (int i = 1; i*(i+1)/2 <= num; i++) {
			v.push_back(i * (i + 1) / 2);
		}

		for (int i = 0; i < v.size(); i++) {
			for (int j = 0; j < v.size(); j++) {
				for (int k = 0; k < v.size(); k++) {
					if (v[i] + v[j] + v[k] == num) {
						count = 1;
						break;
					}
					else
						count = 0;
						continue;
				}
				if (count == 1)break;
			}
			if (count == 1)break;
		}
		if (count == 0)cout << 0<<"\n";
		else cout << 1<<"\n";
	}

}