#include <iostream>
#include <string>
using namespace std;

int main() {
	int alp[26]; //a~z

	memset(alp, -1, sizeof(alp));
	string word;
	cin >> word;

	for (int i = 0; i < word.length(); i++) {
		int a = (int)word[i];
		if (alp[a-97] == -1)alp[a-97] = i;
	}
	for (int i = 0; i < 26; i++) {
		cout << alp[i] << " ";
	}
}