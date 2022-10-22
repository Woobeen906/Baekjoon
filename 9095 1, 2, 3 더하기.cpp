//
//  9095 1, 2, 3 더하기.cpp
//  acmicpc
//
//  Created by 박우빈 on 2022/09/25.
//

#include <iostream>
]
using namespace std;
int arr[12],n,t;

int main(){
    cin>>t;
    arr[1]=1,arr[2]=2,arr[3]=4;
    while (t--) {
        cin>>n;
        
        for(int i=4;i<=n;i++){
            arr[i]=arr[i-1]+arr[i-2]+arr[i-3];
        }
        cout<<arr[n]<<"\n";
    }
}

