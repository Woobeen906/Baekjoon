#include <iostream>
using namespace std;

int main() {
	string word;
	cin >> word;
	int cnt = 1;
	for (int i = 0; i < word.length()-1; i++) {
		if ((word[i] == 'c' && word[i + 1] == '=') || (word[i] == 'c' && word[i + 1] == '-')) continue;
		if ((word[i] == 'd' && word[i + 1] == 'z' && word[i + 2] == '=') || (word[i] == 'd' && word[i + 1] == '-'))continue;
		if (word[i] == 'l' && word[i + 1] == 'j' || word[i] == 'n' && word[i + 1] == 'j' || word[i] == 's' && word[i + 1] == '=' || word[i] == 'z' && word[i + 1] == '=')continue;
		else cnt++;
	}
	cout << cnt;
}