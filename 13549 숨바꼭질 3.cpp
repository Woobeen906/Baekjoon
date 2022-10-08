//
//  13549 숨바꼭질 3.cpp
//  acmicpc
//
//  Created by 박우빈 on 2022/10/09.
//
#include <iostream>
#include <deque>
#include <algorithm>

#define MAX 100001

using namespace std;

deque<int>q;

int n,k,arr[MAX];

void bfs(int n,int k){
    q.push_back(n);
    arr[n]=0;
    
    while (!q.empty()) {
        int x=q.front();
        q.pop_front();
        if(x==k){
            cout<<arr[k];
            return;
        }
        if(2*x<MAX&&arr[2*x]==-1){
            q.push_front(2*x);
            arr[2*x]=arr[x];
        }
        if(x+1<MAX&&arr[x+1]==-1){
            q.push_back(x+1);
            arr[x+1]=arr[x]+1;
        }
        if(x-1>=0&&arr[x-1]==-1){
            q.push_back(x-1);
            arr[x-1]=arr[x]+1;
        }
        
        
    }
}

int main(){
    cin>>n>>k;
    fill(arr, arr+MAX, -1);
    bfs(n,k);
}

