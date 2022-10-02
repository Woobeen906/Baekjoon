//
//  1697 숨바꼭질.cpp
//  acmicpc
//
//  Created by 박우빈 on 2022/10/02.
//

#include <iostream>
#include <queue>
#include <algorithm>

#define MAX 200000

using namespace std;

queue<int>q;

int n,k,arr[MAX+1];

void bfs(int n,int k){
    q.push(n);
    arr[n]=1;
    
    while (!q.empty()) {
        int x=q.front();
        q.pop();
        if(x==k){
            cout<<arr[k]-1;
            return;
        }
        if(2*x<=MAX&&arr[2*x]==0){
            q.push(2*x);
            arr[2*x]=arr[x]+1;
        }
        if(x+1<=MAX&&arr[x+1]==0){
            q.push(x+1);
            arr[x+1]=arr[x]+1;
        }
        if(x-1>=0&&arr[x-1]==0){
            q.push(x-1);
            arr[x-1]=arr[x]+1;
        }
    }
}

int main(){
    cin>>n>>k;
    bfs(n,k);
}
