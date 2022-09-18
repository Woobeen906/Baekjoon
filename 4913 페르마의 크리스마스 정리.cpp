//
//  4913 페르마의 크리스마스 정리.cpp
//  acmicpc
//
//  Created by 박우빈 on 2022/09/18.
//

#include <iostream>

using namespace std;
#define MAX 1000002
int L,U,x,y,arrX[MAX],arrY[MAX],cntX,cntY;
bool visited[MAX],prime[MAX];

void Init(){
    visited[2]=prime[0]=prime[1]=true;
    arrY[2]=1;
    for (int i = 2; i <= MAX; i++) {
        arrX[i]+=arrX[i-1];
        arrY[i]+=arrY[i-1];
        for (int j = 2 * i; j <= MAX; j += i) {
            prime[j] = true;
        }
        if(!prime[i]){
            arrX[i]++;
            if(i%4==1){
                arrY[i]++;
                visited[i]=true;
            }
        }
        
    }
    arrY[0]=0;
}

int main(){
    Init();
    
    while (1) {
        cin>>L>>U;
        x=0;
        y=0;
        if(L==-1&&U==-1)break;
        int start=0,end=0;
        if(L<0)start=0;
        else start=L;
        
        if(U<0)end=0;
        else end=U;
        
        
        int resultX=arrX[end]-arrX[start-1],resultY=arrY[end]-arrY[start-1];
        
        cout<<L<<" "<<U<<" "<<resultX<<" "<<resultY<<"\n";
    }
}
