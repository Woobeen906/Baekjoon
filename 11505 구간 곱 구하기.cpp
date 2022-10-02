//
//  11505 구간 곱 구하기.cpp
//  acmicpc
//
//  Created by 박우빈 on 2022/10/02.
//

#include <iostream>
#include <math.h>
#include <vector>
using namespace std;
#define ll long long
#define MAX 1000001
#define mod 1000000007
ll arr[MAX];
ll tree[MAX * 4];
bool check;

ll init(int node, int start, int end) {
    if (start == end) return tree[node] = arr[start];


    int mid = (start + end) / 2;
    tree[node] = (init(node * 2, start, mid)%mod * init(node * 2 + 1, mid + 1, end)%mod)%mod;


    return tree[node];
}

ll mul(int node, int start, int end, ll left, ll right) {
    if (left > end || right < start)return 1;
    if (left <= start && end <= right)return tree[node]%mod;
    int mid = (start + end) / 2;
    return ((mul(node * 2, start, mid, left, right)%mod )* (mul(node * 2 + 1, mid + 1, end,left, right)%mod))%mod;
}

ll update(int node, int start, int end, ll index, ll diff) {
    if (!(start <= index && index <= end))return tree[node];
    if(start==end)return tree[node]=diff%mod;



    int mid = (start + end) / 2;
    return tree[node]=(update(node * 2, start, mid, index, diff)*update(node * 2 + 1, mid + 1, end, index, diff)%mod);
}

int main() {
    int n, m, k, a;
    ll b, c;
    cin >> n >> m >> k;

    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    init(1, 1, n);
    for (int i=0;i<m+k;i++) {
        cin >> a >> b >> c;
        if (a == 1) {
            update(1, 1, n, b, c);
            if(c==0)check=true;
            arr[b] = c%mod;
        }
        else {
            cout<<mul(1, 1, n, b, c)<<"\n";
        }
    }
}

