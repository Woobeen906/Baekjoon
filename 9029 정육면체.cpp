//
//  9029 정육면체.cpp
//  acmicpc
//
//  Created by 박우빈 on 2022/10/07.
//

#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;
#define MAX 205
int t,w,l,h,dp[MAX][MAX][MAX];


int solve(int w,int l,int h){
    for (int i = 1; i <= w; i++) {
            for (int j = 1; j <= l; j++) {
                for (int k = 1; k <= h; k++) {
                    if (i == j && j == k)dp[i][j][k] = 1;
                    else if (i == 1)dp[i][j][k] = j * k;
                    else if (j == 1)dp[i][j][k] = i * k;
                    else if (k == 1)dp[i][j][k] = j * i;
                    else {
                        dp[i][j][k] = dp[1][j][k] + dp[i - 1][j][k];
                        for (int temp = 1; temp <= ceil(i/2); temp++) {
                            if (dp[temp][j][k] + dp[i - temp][j][k] < dp[i][j][k])dp[i][j][k] = dp[temp][j][k] + dp[i - temp][j][k];
                        }
                        for (int temp = 1; temp <= ceil(j / 2); temp++) {
                            if (dp[i][temp][k] + dp[i][j-temp][k] < dp[i][j][k])dp[i][j][k] = dp[i][temp][k] + dp[i][j - temp][k];
                        }
                        for (int temp = 1; temp <= ceil(k / 2); temp++) {
                            if (dp[i][j][temp] + dp[i][j ][k - temp] < dp[i][j][k])dp[i][j][k] = dp[i][j][temp] + dp[i][j][k - temp];
                        }
                    }
                        
                }
            }
    }
    return dp[w][l][h];
}

int main(){
    cin>>t;
    
    while (t--) {
        int arr[3];
        cin>>arr[0]>>arr[1]>>arr[2];
        sort(arr,arr+3);
        
        cout<< solve(arr[0],arr[1],arr[2])<<"\n";
        
    }
}

