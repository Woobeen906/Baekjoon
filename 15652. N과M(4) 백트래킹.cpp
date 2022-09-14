//
//  15652. N과 M(4) 백트래킹.cpp
//  acmicpc
//
//  Created by 박우빈 on 2022/09/06.
//

#include <iostream>
#include <vector>
using namespace std;

int N,M,arr[8];
bool visited[8];

void Print(){
    for(int i=0;i<M;i++)cout<<arr[i]<<" ";
    cout<<"\n";
}

void Backtrace(int num,int cnt){
    if(cnt==M){
        Print();
        return;
    }
    
    for(int i=num;i<N;i++){
        visited[i]=true;
        arr[cnt]=i+1;
        Backtrace(i,cnt+1);
        visited[i]=false;
    }
    
    
}

int main(){
    cin>>N>>M;
    
    Backtrace(0,0);
}
