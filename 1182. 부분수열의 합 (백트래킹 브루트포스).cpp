//
//  1182. 부분수열의 합 (백트래킹 브루트포스).cpp
//  acmicpc
//
//  Created by 박우빈 on 2022/09/06.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
#define MAX 20
int N,S,result,arr[MAX],sum;
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

void isPromising(){
    int sum=0;
    for(int i=0;i<v.size();i++){
        sum+=v[i];
    }
    if(sum==S)result++;
}


void Backtrace(int num,int cnt){
    if(cnt==N)return;
    
    for(int i=num;i<N;i++){
        if(visited[i])continue;
        
        v.push_back(arr[i]);
        visited[i]=true;
        isPromising();
        Backtrace(i+1,cnt+1);
        v.pop_back();
        visited[i]=false;
    }
}

int main(){
    cin>>N>>S;
    Init();
    Backtrace(0,0);
    cout<<result;
}

