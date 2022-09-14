//
//  2422. 아이스크림 어쩌구 (브루트포스).cpp
//  acmicpc
//
//  Created by 박우빈 on 2022/09/07.
//

#include <iostream>
#include <algorithm>

using namespace std;
int N,M,arr[201],result;
bool visited[201],compare[201][201];

void Init(){
    for(int i=0;i<M;i++){
        int a,b;
        cin>>a>>b;
        compare[a][b]=true;
        compare[b][a]=true;
    }
    
}


void Backtrace(int num,int cnt){
    if(cnt==3){
        if(compare[arr[0]][arr[1]])return;
        else if(compare[arr[1]][arr[2]])return;
        else if(compare[arr[0]][arr[2]])return;
        result++;
        return;
    }
    
    for(int i=num;i<N;i++){
        if(visited[i])continue;
        arr[cnt]=i+1;
        visited[i]=true;
        Backtrace(i+1,cnt+1);
        visited[i]=false;
    }
}

int main(){
    cin>>N>>M;
    Init();
    Backtrace(0,0);
    cout<<result;
}
