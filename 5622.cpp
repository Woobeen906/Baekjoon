#include <iostream>
using namespace std;

int main() {
	string word;
	cin >> word;
	int sum = 0;
	for (int i = 0; i < word.length(); i++) {
		int num = (int)word[i] - 65;
		if (num < 3)sum += 3;
		else if (num < 6)sum += 4;
		else if (num < 9)sum += 5;
		else if (num < 12)sum += 6;
		else if (num < 15)sum += 7;
		else if (num < 19)sum += 8;
		else if (num < 22)sum += 9;
		else if (num < 26)sum += 10;
	}
	cout << sum;
}