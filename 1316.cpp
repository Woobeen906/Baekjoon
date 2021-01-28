#include <iostream>
using namespace std;
int alpcnt[27]; //0은 아무것도 안한거 1은 방문 중 -1은 방문하다 다른걸 만났을 때

//단어의 앞 글자 부터 하나씩 체크한다.
//이 때 이전 단어와 다른 단어를 체크하면 바로 전의 방문한 단어의 값을 -1로 변경한다.
//만약 -1이 된 위치에 알파벳을 다시 방문하면 반복문을 멈추고 카운트는 그대로 둔다.

void init() {
	for (int i = 0; i < 26; i++)alpcnt[i] = 0;
}

int main() {
	int n, groupCnt = 0;;
	cin >> n;
	string word;
	for (int i = 0; i < n; i++) {
		cin >> word;
		for (int j = 0; j < word.length(); j++) {
			if (alpcnt[word[j] - 97] >= 0)alpcnt[word[j] - 97]++;
			if (j>0&&word[j] != word[j - 1])alpcnt[word[j - 1] - 97] = -1;
			if (alpcnt[word[j] - 97] == -1)break;
			if (j == word.length() - 1)groupCnt++;
		}
		init();
	}
	cout << groupCnt;
}