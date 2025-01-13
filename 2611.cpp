#include <iostream>
#include <vector>
#include <stack>
#define MAX 1000
using namespace std;
using pi = pair<int, int>;

vector<pi> edges[MAX + 1];
int dp[MAX + 1];
int parent[MAX + 1];

int dfs(int i) {
    if(i == 1) return 0;
    if(dp[i]) return dp[i];
    for(auto e: edges[i]) {
        int tmp = dfs(e.first) + e.second;
        if(dp[i] > tmp) continue;

        dp[i] = tmp;
        parent[i] = e.first;
    }
    return dp[i];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N, M;
    cin >> N >> M;
    for(int i = 0, p, q, r; i < M; i++) {
        cin >> p >> q >> r;
        edges[p].push_back( { q, r } );
    }

    // dp[i] = i에서 출발해서 1로 돌아갈 때 최대 점수
    for(auto e: edges[1]) {
        int tmp = dfs(e.first) + e.second;
        if(dp[1] > tmp) continue;

        dp[1] = tmp;
        parent[1] = e.first;
    }

    cout << dp[1] << '\n';
    
    vector<int> ans;
    ans.push_back(1);

    // for(int i = 1; i <= N; i++) {
    //     cout << i << ' ';
    // } cout << '\n';

    // for(int i = 1; i <= N; i++) {
    //     cout << dp[i] << ' ';
    // } cout << '\n';

    // for(int i = 1; i <= N; i++) {
    //     cout << parent[i] << ' ';
    // } cout << '\n';

    while(1) {
        int last = ans[ans.size() - 1];
        ans.push_back(parent[last]);
        if(parent[last] == 1) break;
    }

    for(auto v: ans) {
        cout << v << ' ';
    }

    return 0;
}