#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>

#define INF 987654321

using namespace std;

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	long long min, max;
	cin >> min >> max;

	long long ans = max - min + 1; // ������� �ϴ� ������ ����

	vector<bool> sieve(max - min + 1, false);
	long long i = 2; // ó�� �������� 2*2 �̹Ƿ� i=2�� �ʱ�ȭ

		// �������� max���� �۰ų� ���� ���� ����
	while (i * i <= max) {

		// ó������ i*i�� ����������� ���� ã�ƾ� �Ѵ�.
				// ������ ������ !���Ϸ��� ��! �� ���ϱ� ���� ����
		long long sNum = min / (i * i);
		if (min % (i * i) != 0)
			sNum += 1;

		// (!���Ϸ��� ��!�� 1�� ������Ű��) * ������ �� ��� �ε����� true ǥ���ϱ�
		while (sNum * (i * i) <= max) {
			if (sieve[sNum * (i * i) - min] == false) {
				sieve[sNum * (i * i) - min] = true;
				ans -= 1;
				// true�� ǥ���ϴ� ������ ��� ������ �������� �����̹Ƿ�,
				// ������� �ϴ� ������ �� �������� 1���� ���ָ� �ȴ�.
			}
			sNum += 1;
		}
		i += 1; // ���� �������� �Ѿ�� ���� i�� 1 ������Ű��
	}

	cout << ans; // �������� ������ �������� �ʴ� ������ �ȴ�.
	return 0;
}