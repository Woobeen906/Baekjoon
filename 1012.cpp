/*
  백준 1012 유기농배추 문제
*/
#include <iostream>
using namespace std;
int field[51][51];
int visit[51][51];
int n, m, k,cnt;
void dfs(int a, int b) {
    if (a < 0 || a >= n || b < 0 || b >= m || field[a][b] == 0 || visit[a][b] == -1)return;
    else {
        visit[a][b] = -1;
        dfs(a, b + 1);
        dfs(a + 1, b);
        dfs(a - 1, b);
        dfs(a, b - 1);
    }
}

void init() {
    for (int i = 0; i < 51; i++) {
        for (int j = 0; j < 51; j++) {
            field[i][j] = 0;
            visit[i][j] = 0;
        }
    }
}

int main() {
    int T;
    cin >> T;
    for (int test_case = 0; test_case < T; test_case++) {
        
        cin >> n >> m >> k;
        for (int i = 0; i < k; i++) {
            int a, b;
            cin >> a >> b;
            field[a][b] = 1;
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (visit[i][j] == -1||field[i][j]==0)continue;
                else {
                    dfs(i, j);
                    cnt++;
                }
            }
        }
        cout << cnt << '\n';
        cnt = 0;
        init();
    }
}