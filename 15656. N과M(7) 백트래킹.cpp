//
//  15656. N과M(7) 백트래킹.cpp
//  acmicpc
//
//  Created by 박우빈 on 2022/09/06.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
#define MAX 8

int N,M,arr[MAX];
bool visited[MAX];

vector<int>v;

void Init(){
    for(int i=0;i<N;i++){
        int num;
        cin>>num;
        arr[i]=num;
    }
    sort(arr,arr+N);
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
        v.push_back(arr[i]);
        visited[i]=true;
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

