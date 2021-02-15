/*
   백준 2573 빙산 문제
*/
#include <iostream>
using namespace std;
#define MAX 301
int iceberg[MAX][MAX];
bool icebergCheck[MAX][MAX],copyCheck[MAX][MAX];
int year, n, m,lump;



void Melt(int a, int b) { //빙하를 녹이는 함수

	if (icebergCheck[a + 1][b] == false)iceberg[a][b]--;
	if (iceberg[a][b] == 0)return;
	if (icebergCheck[a - 1][b] == false)iceberg[a][b]--;
	if (iceberg[a][b] == 0)return;
	if (icebergCheck[a][b + 1] == false)iceberg[a][b]--;
	if (iceberg[a][b] == 0)return;
	if (icebergCheck[a][b - 1] == false)iceberg[a][b]--;
}


void dfs(int a, int b) { //녹은 빙하가 몇개의 덩어리인지 확인하는 함수
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
		for (int i = 1; i < n - 1; i++) { //행과 열에 맨끝은 모두 0으로 이뤄져있기 떄문에
			for (int j = 1; j < m - 1; j++) { // 1부터 n-1 , m-1 까지 탐색해줘도 된다.
				if (iceberg[i][j] <= 0)continue;
				Melt(i, j);
			}
		}

		for (int i = 1; i < n - 1; i++) {
			for (int j = 1; j < m - 1; j++) {
				check += iceberg[i][j];
			}
		}

		if (check == 0) { //만약 전부 다 녹을때까지 두 덩어리 이상이 안나오면 
			cout << 0;    //반복문을 멈추고 0을 출력한다.
			break;
		}


		for (int i = 1; i < n - 1; i++) { //빙하가 녹은 후 다 녹은 (0이 된) 빙하에 대해
			for (int j = 1; j < m - 1; j++) { //false 처리를 해주며 다음 년도에
				                              //빙하가 녹는 시간을 계산하기 편하게 해준다.
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