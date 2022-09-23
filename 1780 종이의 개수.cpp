//
//  1780 종이의 개수.cpp
//  acmicpc
//
//  Created by 박우빈 on 2022/09/23.
//

#include<iostream>
#include<cmath>

using namespace std;

int N,paper[3000][3000],ans[3],check;

void dfs(int x, int y, int size) {
    
    check = paper[x][y];

    for (int i = x; i < x + size; i++)
        for (int j = y; j < y + size; j++)
        {
            if (paper[i][j] != paper[x][y])
            {
                dfs(x, y, size / 3);
                dfs(x + size * 1 / 3, y, size / 3);
                dfs(x + size * 2 / 3, y, size / 3);
                dfs(x, y + size * 1 / 3, size / 3);
                dfs(x + size * 1 / 3, y + size * 1 / 3, size / 3);
                dfs(x + size * 2 / 3, y + size * 1 / 3, size / 3);
                dfs(x, y + size * 2 / 3, size / 3);
                dfs(x + size * 1 / 3, y + size * 2 / 3, size / 3);
                dfs(x + size * 2 / 3, y + size * 2 / 3, size / 3);
                return;
            }
        }
    ans[paper[x][y] + 1]++;
    return;
}

int main()
{
    cin >> N;

    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            cin >> paper[i][j];
        }
    }
        

    dfs(0, 0, N);

    for (int i = 0; i < 3; i++)cout << ans[i] << "\n";

}
