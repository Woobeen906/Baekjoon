/*
  백준 1018 체스판 다시 칠하기 문제
*/

#include <iostream>
#include <algorithm>
using namespace std;
char board[51][51];
char WB[8][8], BW[8][8];

void make() {
    int count = 0;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (i % 2 == 0 && j % 2 == 0 || i%2==1&&j%2==1) {
                WB[i][j] = 'W';
                BW[i][j] = 'B';
            }
            else{
                WB[i][j] = 'B';
                BW[i][j] = 'W';
            }
        }
    }
}



int B_W(int a, int b) {
    int cnt = 0;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (board[i + a][j + b] != BW[i][j])cnt++;
        }
    }
    return cnt;
}

int W_B(int a, int b) {
    int cnt = 0;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (board[i + a][j + b] != WB[i][j])cnt++;
        }
    }
    return cnt;
}


int main() {
    int n, m, result = 9999;
    cin >> n>> m;
    
    string bw;
    make();
    for (int i = 0; i < n; i++) {
        cin >> bw;
        for (int j = 0; j < m; j++) {
            board[i][j] = bw[j];
        }
    }

    
    for (int i = 0; i <= n - 8; i++) {
        for (int j = 0; j <= m- 8; j++) {
            result=min(min(W_B(i, j), B_W(i, j)),result);
        }
    }
    cout << result;

}