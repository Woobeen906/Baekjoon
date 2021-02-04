#include <iostream>
using namespace std;

int main() {
	int alp[26] = { 0, };
	string word;
	int a, b;

	cin >> word;
	for (int i = 0; i < word.length(); i++) {
		if (word[i] > 64 && word[i] < 97)alp[word[i] - 65]++;
		else alp[word[i] - 97]++;
	}

	int max = 0;
	int save = 0;
	for (int i = 0; i < 26; i++) {
		if (alp[i] > max) {
			max = alp[i];
			save = i;
		}
	}
	int cnt = 0;
	for (int i = 0; i < 26; i++) {
		if (alp[i] == max)cnt++;
	}

	if (cnt >= 2)cout << '?';
	else cout << (char)(save+65);
	
	
}