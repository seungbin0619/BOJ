#include <bits/stdc++.h>
#define MAX 3000
#define MOD 1000000009
using namespace std;
using pi = pair<int, int>;

int N, M;
char board[MAX][MAX];
int dp[MAX][MAX];

int dfs(int r, int c) {
    if(r >= N || c >= M) return 0;
    if(dp[r][c]) return dp[r][c];

    if(board[r][c] == 'E') {
        dp[r][c] = dfs(r, c + 1);
    } else if(board[r][c] == 'S') {
        dp[r][c] = dfs(r + 1, c);
    } else {
        dp[r][c] = dfs(r + 1, c) + dfs(r, c + 1);
        dp[r][c] %= MOD;
    }

    return dp[r][c];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int ans = 0;
    cin >> N >> M;
    for(int r = 0; r < N; r++) {
        for(int c = 0; c < M; c++) {
            cin >> board[r][c];
        }
    }

    // E(→): c + 1 
    // S(↓): r + 1 
    // B(→ or ↓): c + 1 or r + 1 

    dp[N - 1][M - 1] = 1;

    for(int r = 0; r < N; r++) {
        for(int c = 0; c < M; c++) {
            dp[r][c] = dfs(r, c);
            ans += dp[r][c];
            ans %= MOD;
        }
    }

    cout << ans;

    return 0;
}