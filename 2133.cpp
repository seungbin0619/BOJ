#include <bits/stdc++.h>
#define MAX 30
using namespace std;
using ll = long long;

ll dp[MAX + 1];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    // 홀수는 안됨.
    int N;
    cin >> N;

    dp[0] = 1;
    dp[2] = 3;

    for(int i = 4; i <= N; i += 2) {
        dp[i] = dp[i - 2] * 4 - dp[i - 4];
    }

    cout << dp[N];

    return 0;
}