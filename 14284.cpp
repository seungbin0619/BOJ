#include <bits/stdc++.h>
#define MAX 5000
using namespace std;
using pi = pair<int, int>;

vector<pi> edges[MAX + 1];
int dist[MAX + 1];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m;
    cin >> n >> m;
    
    for(int i = 0, u, v, c; i < m; i++) {
        cin >> u >> v >> c;

        edges[u].push_back( { v, c } );
        edges[v].push_back( { u, c } );
    }

    for(int i = 1; i <= n; i++) {
        dist[i] = 1e9;
    }

    int s, t;
    cin >> s >> t;
    priority_queue<pi> pq;

    dist[s] = 0;
    pq.push( { 0, s } );

    while(pq.size()) {
        int v = pq.top().second;
        int c = -pq.top().first;
        pq.pop();

        if(dist[v] < c) continue;

        for(auto e: edges[v]) {
            if(dist[e.first] <= c + e.second) continue;

            dist[e.first] = c + e.second;
            pq.push( { -c - e.second, e.first } );
        }
    }

    cout << dist[t];

    return 0;
}