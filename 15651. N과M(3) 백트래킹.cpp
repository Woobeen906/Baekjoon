//
//  15651. N과M(3) 백트래킹.cpp
//  acmicpc
//
//  Created by 박우빈 on 2022/09/05.
//

#include <iostream>
#include <vector>

using namespace std;

int N,M,arr[8];
bool visited[8];
vector<int>v;

void Init(){
    for(int i=0;i<N;i++)arr[i]=i+1;
}

void Print(){
    for(int i=0;i<M;i++)cout<<v[i]<<" ";
    cout<<"\n";
}

void Backtrace(int cnt){
    if(cnt==M){
        Print();
        return;
    }
    
    for(int i=0;i<N;i++){
        visited[i]=true;
        v.push_back(arr[i]);
        Backtrace(cnt+1);
        v.pop_back();
        visited[i]=false;
    }
}

int main(){
    cin>>N>>M;
    Init();
    Backtrace(0);
}
