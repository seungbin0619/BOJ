#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 4000
using namespace std;
using pi = pair<int, int>;

pi E[MAX];
vector<int> edges[MAX + 1];
int A[MAX + 1][MAX + 1];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N, M;
    cin >> N >> M;

    for(int i = 0, u, v; i < M; i++) {
        cin >> u >> v;
        A[u][v] = A[v][u] = 1;
        E[i] = { u, v };
        edges[u].push_back(v);
        edges[v].push_back(u);
    }

    int ans = MAX * MAX, flag = 0;

    for(int i = 0, u, v, tmp; i < M; i++) {
        u = E[i].first, v = E[i].second;

        tmp = MAX + 1;
        for(int i = 1; i <= N; i++) {
            if(u == i || v == i) continue;
            if(!A[u][i] || !A[i][v]) continue;

            // u, v, i는 셋이 친구.
            tmp = min(tmp, -2 + (int)edges[i].size());
            flag = 1;
        }

        tmp += edges[u].size() + edges[v].size() - 4;
        ans = min(ans, tmp);
    }

    if(!flag) cout << -1;
    else cout << ans;

    return 0;
}