#include <bits/stdc++.h>
#define MAX 100000
using namespace std;

vector<int> edges[MAX + 1];
int visited[MAX + 1], order;

void dfs(int n) {
    for(auto e: edges[n]) {
        if(visited[e]) continue;
        visited[e] = ++order;
        
        dfs(e);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N, M, R;
    cin >> N >> M >> R;

    for(int i = 0, u, v; i < M; i++) {
        cin >> u >> v;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }

    for(int i = 1; i <= N; i++) {
        // visited[i] = -1;
        sort(edges[i].begin(), edges[i].end(), greater<int>());
    }

    order = visited[R] = 1;
    dfs(R);

    for(int i = 1; i <= N; i++) {
        cout << visited[i] << '\n';
    }

    return 0;
}