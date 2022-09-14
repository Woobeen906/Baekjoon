//
//  10974. 모든 순열 (브루트포스, 백트래킹).cpp
//  acmicpc
//
//  Created by 박우빈 on 2022/09/06.
//

#include <iostream>

using namespace std;
#define MAX 8

int N,arr[MAX];
bool visited[MAX];

void Print(){
    for(int i=0;i<N;i++)cout<<arr[i]<<" ";
    cout<<"\n";
}

void Backtrace(int cnt){
    if(cnt==N){
        Print();
        return;
    }
    
    for(int i=0;i<N;i++){
        if(visited[i])continue;
        
        arr[cnt]=i+1;
        visited[i]=true;
        Backtrace(cnt+1);
        visited[i]=false;
    }
}

int main(){
    cin>>N;
    Backtrace(0);
    
}
