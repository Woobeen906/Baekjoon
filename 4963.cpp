/*
  ���� 4963�� ���� ���� ����
*/
#include <iostream>
using namespace std;

int island[51][51];
int w, h;
void dfs(int a, int b) {
    if (a < 0 || a >= h || b < 0 || b >= w || island[a][b]==0||island[a][b]==-1)return;
    // ���� ��ǥ(a,b) ������ ����ų�
    // island[a][b] �� ���� ��� (island[a][b]==0)
    // island[a][b] �� �̹� �湮�� -1�� ��쿡�� �Լ��� �������� �ʴ´�.

    island[a][b] = -1; //�湮�� ���� -1�� ǥ��

    dfs(a, b + 1);
    dfs(a, b - 1);
    dfs(a + 1, b);
    dfs(a - 1, b);
    dfs(a + 1, b + 1);
    dfs(a + 1, b - 1);
    dfs(a - 1, b + 1);
    dfs(a - 1, b - 1);
    //�����¿�, �밢���� Ȯ���Ѵ�.
}

void init(int a, int b) {
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            island[i][j] = 0;
        }
    }
} //�迭 �ʱ�ȭ

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