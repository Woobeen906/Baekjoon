#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;


int main() {
	int n, maxlength = 0;
	cin >> n;
	vector<string> words;
	for (int i = 0; i < n; i++) {
		string word;
		cin >> word;
		words.push_back(word);
		if (maxlength < word.length())maxlength=word.length();
	}
	sort(words.begin(), words.end());
	words.erase(unique(words.begin(), words.end()), words.end());

	vector<string>answer;
	for (int i = 1; i <= maxlength; i++) {
		for (int j = 0; j < words.size(); j++) {
			if (words[j].length() == i)answer.push_back(words[j]);
		}
	}
	for (int i = 0; i < answer.size(); i++) {
		cout << answer[i] << "\n";
	}
}