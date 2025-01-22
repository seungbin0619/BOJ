#include <bits/stdc++.h>
#define MAX 100000
using namespace std;
using ll = long long;

vector<ll> P[MAX + 1];
unordered_map<ll, ll> V[MAX + 1];

ll g(int m, int n) {
    if(V[m].count(n)) return V[m][n];
    return 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    ll N, M, ans = 0;
    cin >> N >> M;

    for(ll i = 1; i <= N; i++)
        P[i].push_back(0);

    for(ll i = 1, l; i <= M; i++) {
        cin >> l;

        for(ll j = 0, p, v; j < l; j++) {
            cin >> p >> v;

            P[p].push_back(i);
            V[i][p] = v;
            // V[i][j] = i번 사람의 j에 대한 가치치
        }
    }

    // P[i][j] -> i번 음식을 j번째로 받는 사람의 번호.
    // V[P[i][j]] -> i번 음식을 j번째 사람이 받으면 얻는 가치

    ll dp[MAX + 1];
    for(ll i = 1, j; i <= N; i++) {
        dp[0] = 0;
        dp[1] = V[P[i][1]][i];

        for(j = 2; j < P[i].size(); j++) {
            ll p1, p2;
            p1 = P[i][j];
            p2 = P[i][j - 1];

            if(p1 - p2 > 1) { 
                dp[j] = dp[j - 1] + g(p1, i);
                continue;
            }

            dp[j] = max(dp[j - 2] + g(p1, i), dp[j - 1]);
            dp[j] = max(dp[j], dp[j - 1]);
        }

        ans += dp[P[i].size() - 1];
    }

    // 4 5 6 7
    // 4 5 10 12
    // 

    cout << ans;

    return 0;
}