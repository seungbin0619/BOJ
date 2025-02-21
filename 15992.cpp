#include <bits/stdc++.h>
#define MOD 1000000009
#define MAX 1000
using namespace std;

int dp[MAX + 1][MAX + 1];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    dp[1][1] = dp[2][1] = dp[3][1] = 1;
    for(int i = 2; i <= MAX; i++) {
        for(int j = 2; j <= i; j++) {
            for(int k = 1; k <= min(i, 3); k++) {
                dp[i][j] += dp[i - k][j - 1];
                dp[i][j] %= MOD;
            }
        }
    }

    int t, n, m;
    cin >> t;
    while(t--) {
        cin >> n >> m;

        cout << dp[n][m] << '\n';
    }

    return 0;
}