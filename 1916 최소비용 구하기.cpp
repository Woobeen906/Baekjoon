//
//  1916.cpp
//  acmicpc
//
//  Created by 박우빈 on 2022/10/08.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

const int MAX = 1002, INF = 0x7fffffff;
int dist[MAX],dp[MAX];
int v, e, s,en;

typedef pair<int, int> p;
vector<p> graph[MAX];
priority_queue<p, vector<p>, greater<p> > q;

void dijkstra(int start) {
    dist[start] = 0;
    q.push(p(0, start));
    
    while (!q.empty()) {
        int current=q.top().second;
        int cost=q.top().first;
        
        q.pop();
        if(cost>dist[current])continue;
        
        for(int i=0;i<graph[current].size();i++){
            int next=graph[current][i].first;
            int nextCost=dist[current]+graph[current][i].second;
            
            if(nextCost<dist[next]){
                dist[next]=nextCost;
                q.push(p(nextCost,next));
            }
        }
    }
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> v >> e;
    fill(dist, dist + MAX, INF);
    
    for (int i = 0; i < e; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back(p(v, w));
    }
    cin>>s>>en;
    dijkstra(s);
//    for(int i=0;i<=en;i++)cout<<dist[i]<<" ";
    cout<<dist[en];
    
}
