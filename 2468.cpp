/*
   백준 2468 안전 영역 문제
*/
#include <iostream>
#include <algorithm>
using namespace std;
#define MAX 101
int area[MAX][MAX];
bool visitArea[MAX][MAX];

int n,cnt;

void init(int a) {  //dfs함수를 사용할 때 방문한 지역인지를 표시하는 배열을 초기화하는 함수
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

void safeArea(int a) { // 강우량 a에 대해 잠기지 않는 안전지역들을 표시하는 함수
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (area[i][j] > a)visitArea[i][j] = true; //잠기지 않는 지역들
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
            rainfall = max(a, rainfall);  //브루트포스 범위를 위한 최대 강우량
            area[i][j] = a; //지역에 높이
        }
    }
    
    for (int rain = 0; rain <= rainfall; rain++) {
        safeArea(rain); // 강우량에 따라 잠기는 지역을 구분한다.
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

        init(n); //다음 강우량에 대한 dfs함수사용을 위해 방문여부를 초기화
    }
    cout << result;
}
