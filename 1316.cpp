#include <iostream>
using namespace std;
int alpcnt[27]; //0�� �ƹ��͵� ���Ѱ� 1�� �湮 �� -1�� �湮�ϴ� �ٸ��� ������ ��

//�ܾ��� �� ���� ���� �ϳ��� üũ�Ѵ�.
//�� �� ���� �ܾ�� �ٸ� �ܾ üũ�ϸ� �ٷ� ���� �湮�� �ܾ��� ���� -1�� �����Ѵ�.
//���� -1�� �� ��ġ�� ���ĺ��� �ٽ� �湮�ϸ� �ݺ����� ���߰� ī��Ʈ�� �״�� �д�.

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