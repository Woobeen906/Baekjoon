/*
    �����佺�׳׽��� ü
    1. 2���� N������ ��� ������ ���´�.
    2. ���� ������ ���� �� �� ���� ���� ���� ã�´�. �� ���� �Ҽ��̴�.
    3. �� �Ҽ��� ����� ���� ������ ���� �� �Ҽ��� ����� ��� �����
    4. �� ������ �ݺ��Ѵ�.

*/
#include <iostream>
using namespace std;
int arr[1000002];
int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,m,num,cnt=0;
    cin >> m>>n;

    for (int i = 2; i <=n; i++) {
        arr[i] = 1;
    }
    for (int i = 2; i <= n; i++) {
        for (int j = i + i; j <= n; j += i)arr[j] = 0;
    }
    for (int i = m; i <= n; i++)if (arr[i] == 1)cout << i<<"\n";
}