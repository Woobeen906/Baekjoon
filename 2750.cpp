#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int>v;
int main() {
    int n, num;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> num;
        v.push_back(num);
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < n; i++)cout << v[i] << "\n";
}