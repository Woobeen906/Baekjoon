/*
  백준 4963번 섬의 개수 문제
*/
#include <iostream>
using namespace std;

int island[51][51];
int w, h;
void dfs(int a, int b) {
    if (a < 0 || a >= h || b < 0 || b >= w || island[a][b]==0||island[a][b]==-1)return;
    // 섬의 좌표(a,b) 범위를 벗어나거나
    // island[a][b] 가 섬인 경우 (island[a][b]==0)
    // island[a][b] 가 이미 방문한 -1인 경우에는 함수를 실행하지 않는다.

    island[a][b] = -1; //방문한 섬은 -1로 표시

    dfs(a, b + 1);
    dfs(a, b - 1);
    dfs(a + 1, b);
    dfs(a - 1, b);
    dfs(a + 1, b + 1);
    dfs(a + 1, b - 1);
    dfs(a - 1, b + 1);
    dfs(a - 1, b - 1);
    //상하좌우, 대각선을 확인한다.
}

void init(int a, int b) {
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            island[i][j] = 0;
        }
    }
} //배열 초기화

int main() {
    for (int test_case = 1;; test_case++) {
        cin >> w >> h;
        if (w == 0 && h == 0)break;
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                int a;
                cin >> a;
                island[i][j] = a;
            }
        }

        int cnt = 0;
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                if (island[i][j] == 1) {
                    dfs(i, j);
                    cnt++;
                }
                else continue;
            }
        }
        cout << cnt << "\n";
        init(h, w);
    }
}