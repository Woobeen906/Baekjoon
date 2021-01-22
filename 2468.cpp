/*
   ���� 2468 ���� ���� ����
*/
#include <iostream>
#include <algorithm>
using namespace std;
#define MAX 101
int area[MAX][MAX];
bool visitArea[MAX][MAX];

int n,cnt;

void init(int a) {  //dfs�Լ��� ����� �� �湮�� ���������� ǥ���ϴ� �迭�� �ʱ�ȭ�ϴ� �Լ�
    for (int i = 0; i < a; i++) {
        for (int j = 0; j < a; j++) {
            visitArea[i][j] = false;
        }
    }
}

void dfs(int a, int b) {
    if (a < 0 || b < 0 || a >= n || b >= n||!visitArea[a][b])return; 

    visitArea[a][b] = false;
    dfs(a, b + 1);
    dfs(a, b - 1);
    dfs(a + 1, b);
    dfs(a - 1, b);
}

void safeArea(int a) { // ���췮 a�� ���� ����� �ʴ� ������������ ǥ���ϴ� �Լ�
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (area[i][j] > a)visitArea[i][j] = true; //����� �ʴ� ������
        }
    }
}

int main() {
    int  rainfall = 0, result = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int a;
            cin >> a;
            rainfall = max(a, rainfall);  //���Ʈ���� ������ ���� �ִ� ���췮
            area[i][j] = a; //������ ����
        }
    }
    
    for (int rain = 0; rain <= rainfall; rain++) {
        safeArea(rain); // ���췮�� ���� ���� ������ �����Ѵ�.
        cnt = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (visitArea[i][j]) { 
                    dfs(i,j); 
                    cnt++;
                }
            }
        }
        result = max(result, cnt);

        init(n); //���� ���췮�� ���� dfs�Լ������ ���� �湮���θ� �ʱ�ȭ
    }
    cout << result;
}
