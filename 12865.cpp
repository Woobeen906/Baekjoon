#include <iostream>
using namespace std;
int item[102][2], dp[102][100'003];

int main()
{
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> item[i][0] >> item[i][1];
    }

    for (int i = 1; i <= n; i++)
    {
        int w = item[i][0], val = item[i][1];
        for (int j = 0; j <= k ; j++)
        {
            if (j < item[i][0]) dp[i][j] = dp[i - 1][j];
            else dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w] + val);
        }
    }

    cout << dp[n][k];
}