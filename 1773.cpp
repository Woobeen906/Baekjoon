#include <iostream>
using namespace std;

bool arr[2000000];
int main() {
	int n,c;
	cin >> n>>c;

	int count = 0;
	int stu;
	int num = 0;
	for (int i = 0; i < n; i++) {
		cin >> stu;
		if (arr[stu] == false) {
			for (int j=stu;j<=c;j+=stu) {
				arr[j] = true;
			}
		}
	}
	
	for (int i = 0; i <= c; i++) {
		if (arr[i]==true)count++;
	}
	cout << count;
}