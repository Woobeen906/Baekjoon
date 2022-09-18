//
//  k번째 소수.cpp
//  acmicpc
//
//  Created by 박우빈 on 2022/09/15.
//

#include <iostream>
#include <cmath>
using namespace std;
#define MAX 7368790
int k,cnt=1;
bool check[MAX];
void PrimeNumber(){
    for(int i=2;i<=sqrt(MAX);i++){
        if(check[i])continue;
        else{
            for(int j=i*i;j<=MAX;j+=i)check[j]=true;
        }
    }
}

int main(){
    cin>>k;
    check[1]=true;
    PrimeNumber();
    for(int i=2;i<=MAX;i++){
        if(check[i])continue;
        if(cnt==k){
            cout<<i;
            break;
        }
        if(!check[i])cnt++;
    }
}
