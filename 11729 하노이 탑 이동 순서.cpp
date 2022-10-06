//
//  11729 하노이 탑 이동 순서.cpp
//  acmicpc
//
//  Created by 박우빈 on 2022/09/25.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n,k;
vector<pair<int, int>>v;

void move(int start,int end,int block){
    
    v.push_back(make_pair(start, end));
    cout<<start<<" "<<end<<"\n";
    k++;
}

void hanoi(int start,int mid,int end,int block){
    if(block==1){
        move(start,end,block);
        return;
    }
    hanoi(start,end,mid,block-1);
    move(start,end,block);
    hanoi(mid,start,end,block-1);
}


int main(){
    cin>>n;
    
    hanoi(1,2,3,n);
    cout<<k<<"\n";
    for(int i=0;i<k;i++)cout<<v[i].first<<" "<<v[i].second<<"\n";
}
