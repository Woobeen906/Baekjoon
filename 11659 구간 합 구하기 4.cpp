//
//  11659 구간 합 구하기 4.cpp
//  acmicpc
//
//  Created by 박우빈 on 2022/10/01.
//

#include <iostream>

using namespace std;
#define MAX 100001

int arr[MAX],cumsum[MAX],n,m;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>n>>m;
    
    for(int i=0;i<n;i++){
        cin>>arr[i];
        if(i==0)cumsum[i]=arr[i];
        else cumsum[i]=arr[i]+cumsum[i-1];
    }
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;

        cout<<cumsum[b-1]-cumsum[a-1]+arr[a-1]<<"\n";
    }
    
}
