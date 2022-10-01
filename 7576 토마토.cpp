//
//  7576 토마토.cpp
//  acmicpc
//
//  Created by 박우빈 on 2022/10/01.
//

#include <iostream>
#include <queue>
using namespace std;
#define MAX 1001
int m,n,arr[MAX][MAX];
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

struct tomato{
    int x,y;
};

queue<tomato>q;

bool invaild(int x,int y){
    if(x<0||x>=m||y<0||y>=n)return false;
    return true;
}

void bfs(){
    while (!q.empty()) {
        
        int y=q.front().y;
        int x=q.front().x;
        
        q.pop();
        
        for(int i=0;i<4;i++){
            int nx=dx[i]+x;
            int ny=dy[i]+y;
            if(invaild(nx, ny)&&arr[ny][nx]==0){
                arr[ny][nx]=arr[y][x]+1;
                q.push({nx,ny});
            }
        }
    }
}


int main(){
    cin>>m>>n;
    
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>arr[i][j];
            if(arr[i][j]==1)q.push({j,i});
        }
    }
    
    bfs();
    
    int result=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            
            if(arr[i][j]==0){
                cout<<"-1\n";
                return 0;
            }
            if(arr[i][j]>result){
                result=arr[i][j];
            }
        }
    }
    cout<<result-1;
}
