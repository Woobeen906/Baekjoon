/*
  백준 11724 연결 요쇼의 개수 문제
*/
#include <iostream>
#include <vector>
using namespace std;
vector<int> v[1001];
int visit[1001];

void dfs(int a) {
    visit[a] = true;
    for (int i = 0; i < v[a].size(); i++) {
        int x = v[a][i];
        if (!visit[x])dfs(x);
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a,b;
        cin >> a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    int cnt = 0;

    for (int i = 1; i <=n; i++) {
        if (!visit[i]) {
            cnt++;
            dfs(i);
        }
    }
    cout << cnt;

}