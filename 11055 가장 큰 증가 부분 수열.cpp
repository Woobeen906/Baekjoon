//
//  11055 가장 큰 증가 부분 수열.cpp
//  acmicpc
//
//  Created by 박우빈 on 2022/09/22.
//

#include <iostream>
#include <algorithm>
using namespace std;
int dp[1001],arr[1001],ans;

int main(){
    int n;
    cin>>n;
    
    for (int i = 1; i <= n; i++)
       {
           cin >> arr[i];
           dp[i] = arr[i];
       }
    
       for (int i = 1; i <= n; i++)
       {
           for (int j = 1; j < i; j++)
           {
               if (arr[i] > arr[j])
               {
                   dp[i] = max(dp[i], dp[j] + arr[i]);
               }
           }
           ans = max(ans, dp[i]);
       }
       cout << ans;

    
}
