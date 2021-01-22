#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
int N[1000]; //각 건물 건설 시간
int degree[1000];
int result[1000]; //건물 짓는데 걸리는 최소시간
int n, k, x, y;
int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int tc = 0;//테스트 케이스
	cin >> tc;
	for (int testcase = 1; testcase <= tc; testcase++) {

		cin >> n >> k;

		vector<int> v[1000];
		queue<int> q;
		for (int i = 0; i < n; i++) {
			cin >> N[i]; //각 건물 건설 시간
		}
		for (int i = 0; i < k; i++) {
			cin >> x >> y;
			v[x - 1].push_back(y - 1);
			degree[y - 1]++;
		}

		int w; //지어야 하는 건물 번호
		cin >> w;
		w--;
		for (int i = 0; i < n; i++) {
			if (!degree[i])q.push(i);
		}

		while (degree[w] > 0)
		{
			int p = q.front();
			q.pop();
			for (int i = 0; i < v[p].size(); i++) {
				int l = v[p][i];
				result[l] = max(result[l], result[p] + N[p]);
				if (--degree[l] == 0)q.push(l);
			}
		}
		cout << result[w] + N[w] << "\n";
		memset(N, 0, sizeof(N));
		memset(degree, 0, sizeof(degree));
		memset(result, 0, sizeof(result));
	}
}