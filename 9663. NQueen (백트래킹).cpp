//
//  9663. NQueen (백트래킹).cpp
//  acmicpc
//
//  Created by 박우빈 on 2022/09/06.
//

#include <iostream>

using namespace std;
#define MAX 15
int n,result;

int board[15];

bool isPromising(int cdx){
    for(int i=0;i<cdx;i++){
        if(board[i]==board[cdx]||cdx-i==abs(board[cdx]-board[i]))return false;
    }
    return true;
}

void nqueen(int cnt) {
    if(cnt==n){
        result++;
        return;
    }
    
    for(int i=0;i<n;i++){
        board[cnt]=i;
        
        if(isPromising(cnt)){
            nqueen(cnt+1);
        }
        
    }
}

int main(){
    cin>>n;
    nqueen(0);
    cout<<result;
}
