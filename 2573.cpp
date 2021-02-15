/*
   ���� 2573 ���� ����
*/
#include <iostream>
using namespace std;
#define MAX 301
int iceberg[MAX][MAX];
bool icebergCheck[MAX][MAX],copyCheck[MAX][MAX];
int year, n, m,lump;



void Melt(int a, int b) { //���ϸ� ���̴� �Լ�

	if (icebergCheck[a + 1][b] == false)iceberg[a][b]--;
	if (iceberg[a][b] == 0)return;
	if (icebergCheck[a - 1][b] == false)iceberg[a][b]--;
	if (iceberg[a][b] == 0)return;
	if (icebergCheck[a][b + 1] == false)iceberg[a][b]--;
	if (iceberg[a][b] == 0)return;
	if (icebergCheck[a][b - 1] == false)iceberg[a][b]--;
}


void dfs(int a, int b) { //���� ���ϰ� ��� ������� Ȯ���ϴ� �Լ�
	if (copyCheck[a][b] == false)return;

	copyCheck[a][b] = false;
	dfs(a, b + 1);
	dfs(a, b - 1);
	dfs(a + 1, b);
	dfs(a - 1, b);
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int num;
			cin >> num;
			iceberg[i][j] = num;
			if (num != 0)icebergCheck[i][j] = true;
		}
	}

	for (;;) {
		int check = 0;
		lump = 0;
		for (int i = 1; i < n - 1; i++) { //��� ���� �ǳ��� ��� 0���� �̷����ֱ� ������
			for (int j = 1; j < m - 1; j++) { // 1���� n-1 , m-1 ���� Ž�����൵ �ȴ�.
				if (iceberg[i][j] <= 0)continue;
				Melt(i, j);
			}
		}

		for (int i = 1; i < n - 1; i++) {
			for (int j = 1; j < m - 1; j++) {
				check += iceberg[i][j];
			}
		}

		if (check == 0) { //���� ���� �� ���������� �� ��� �̻��� �ȳ����� 
			cout << 0;    //�ݺ����� ���߰� 0�� ����Ѵ�.
			break;
		}


		for (int i = 1; i < n - 1; i++) { //���ϰ� ���� �� �� ���� (0�� ��) ���Ͽ� ����
			for (int j = 1; j < m - 1; j++) { //false ó���� ���ָ� ���� �⵵��
				                              //���ϰ� ��� �ð��� ����ϱ� ���ϰ� ���ش�.
				if (iceberg[i][j] <= 0)icebergCheck[i][j] = false;
			}
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				copyCheck[i][j]=icebergCheck[i][j];
			}
		}

		for (int i = 1; i < n - 1; i++) {
			for (int j = 1; j < m - 1; j++) {
				if (copyCheck[i][j] == false)continue;
				dfs(i, j);
				lump++;
			}
		}
		year++;
		if (lump >= 2) {
			cout << year;
			break;
		}
	}
}