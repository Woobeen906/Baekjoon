//
//  1759. 암호 만들기 백트래킹.cpp
//  acmicpc
//
//  Created by 박우빈 on 2022/09/06.
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
#define MAX 15

char arr[MAX];
int L,C;
bool visited[MAX];
vector<char>v;

void Init(){
    for(int i=0;i<C;i++){
        char word;
        cin>>word;
        arr[i]=word;
    }
    sort(arr,arr+C);
    
}

bool Promising(){
    int cnt=0;
    char consonant[5]={'a','e','i','o','u'};
    for(int i=0;i<5;i++){
        if(find(v.begin(),v.end(),consonant[i])!=v.end()){  //find return 값이 v.end()와 다르면 해당 원소가 존재함
            cnt++;
        }
    }
    if(cnt>=1&&L-cnt>=2)return true;
    else return false;
}

void Print(){
    for(int i=0;i<L;i++)cout<<v[i];
    cout<<"\n";
}

void Backtrace(int num,int cnt){
    if(cnt==L){
        if(Promising())Print();
        return;
    }
    
    for(int i=num;i<C;i++){
        if(visited[i])continue;
        v.push_back(arr[i]);
        visited[i]=true;
        
        Backtrace(i+1,cnt+1);
        v.pop_back();
        visited[i]=false;
    }
}

int main(){
    cin>>L>>C;
    Init();
    Backtrace(0,0);
    
}
