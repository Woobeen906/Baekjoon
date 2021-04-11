#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

int main()
{
	string str, bomb, result;

	cin >> str >> bomb;

	for (int i = 0; i < str.size(); i++) {
		result += str[i];
		if (str[i] == bomb[bomb.length() - 1] && i >= bomb.length() - 1) {
			bool chack = true;
			for (int j = 0; j < bomb.length(); j++) {
				if (result[result.size() - bomb.length() + j] != bomb[j]) {
					chack = false;
					break;
				}
			}
			if (chack)for (int j = 0; j < bomb.length(); j++) result.pop_back();
		}
	}
	if (!result.empty())cout << result;
	else cout << "FRULA";
}