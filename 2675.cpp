#include <iostream>
using namespace std;

int main() {
	int T;
	cin >> T;
	for (int t = 0; t < T; t++) {
		int cnt;
		string word;
		cin >> cnt>>word;

		for (int i = 0; i < word.length(); i++) {
			for (int j = 0; j < cnt; j++)cout << word[i];
		}
		cout << '\n';
	}
}