/*
   백준 15596 정수 n개의 합 문제

   정수 n개가 주어졌을 때, n개의 합을 구하는 함수를 구현하는 문제
*/

#include <iostream>
#include <vector>
using namespace std;
vector<int> a;

long long sum(vector<int>& a) {
    long long ans = 0;
    for (int i = 0; i < a.size(); i++) {
        ans += a[i];
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        a.push_back(num);
    }
    cout<<sum(a);
}