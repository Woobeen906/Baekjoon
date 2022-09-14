//
//  12015. 가장 긴 증가하는 부분수열2 (이분탐색, LIS).cpp
//  acmicpc
//
//  Created by 박우빈 on 2022/09/06.
//

#include <iostream>
#include <algorithm>

using namespace std;
#define MAX 1000000
int N,len,arr[MAX];

void LIS(){
    for(int i=0;i<N;i++){
        int num;
        cin>>num;
        int *pos=lower_bound(arr, arr+len, num);
        *pos=num;
        
        if(pos==arr+len)len++;
    }
}

int main(){
    cin>>N;
    LIS();
    cout<<len;
}
