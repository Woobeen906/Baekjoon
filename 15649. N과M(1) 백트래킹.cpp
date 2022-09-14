//
//  15649.N과 M(1) 백트레킹.cpp
//  acmicpc
//
//  Created by 박우빈 on 2022/09/04.
//

#include <iostream>
#include <vector>

using namespace std;
#define MAX 8

int arr[MAX],N,M;
bool visited[MAX];


vector<int>v;

void Init(int N){
    for(int i=1;i<=N;i++)arr[i-1]=i;
}

void PrintArr(){
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    cout<<"\n";
}

void Backtrace(int cnt){
    if(cnt==M){
        PrintArr();
        return;
    }
    
    for(int i=0;i<N;i++){
        if(visited[i])continue;
        visited[i]=true;
        v.push_back(arr[i]);
        Backtrace(cnt+1);
        v.pop_back();
        visited[i]=false;
    }
}

int main(){
    
    cin>>N>>M;
    
    Init(N);
    Backtrace(0);
    
}
