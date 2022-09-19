//
//  1644 소수의 연속합.cpp
//  acmicpc
//
//  Created by 박우빈 on 2022/09/19.
//

#include <iostream>
#include <vector>

using namespace std;

int n;
vector<int>v;


void Print(){
    for(int i=0;i<v.size();i++)cout<<v[i];
    cout<<"\n";
}

bool isPrime(int num){
    for(int i=2;i*i<=num;i++){
        if(num%i==0)return false;
    }
    return true;
}

void Backtrace(int num,int cnt){

    if(cnt==n){
        int temp=0;
        for(int i=0;i<v.size();i++){
        
            temp+=v[i];
            if(!isPrime(temp))return;
            temp*=10;
            if(i==v.size()-1)Print();
        }
//        Print();
        return;
    }
    
    
    for(int i=1;i<10;i++){
        if(cnt==0&&(i==1||i==4||i==6||i==8||i==9))continue;
        else if(cnt!=0&&(i==2||i==4||i==5||i==6||i==8))continue;
        else if(cnt==n-1&&(i==2||i==4||i==5||i==6||i==8))continue;
        
        
        v.push_back(i);
        Backtrace(i, cnt+1);
        v.pop_back();
    }
}

int main(){
    cin>>n;
    if(n==1){
        for(int i=2;i<10;i++){
            if(isPrime(i))
            cout<<i<<"\n";
        }
    }
    else Backtrace(n, 0);
}
