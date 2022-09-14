//
//  15650. N과M(2) 백트래킹.cpp
//  acmicpc
//
//  Created by 박우빈 on 2022/09/05.
//

#include <iostream>
#include <vector>
using namespace std;

int arr[8],N,M;
bool visited[8];
vector<int>v;

void Init(){
    for(int i=0;i<N;i++)arr[i]=i+1;
}

void Print(){
    for(int i=0;i<M;i++){
        cout<<v[i]<<" ";
    }
    cout<<"\n";
}

void BackTrace(int num,int cnt){
    if(cnt==M){
        Print();
        return;
    }
    
    for(int i=num;i<N;i++){
        if(visited[i])continue;
        visited[i]=true;
        v.push_back(arr[i]);
        BackTrace(i+1,cnt+1);
        v.pop_back();
        visited[i]=false;
    }
    
}

int main(){
    cin>>N>>M;
    Init();
    BackTrace(0,0);
}
