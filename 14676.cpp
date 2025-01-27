#include <bits/stdc++.h>
#define MAX 100000
using namespace std;

int built[MAX + 1]; // build[i] = i번 건물 개수
int entry[MAX + 1]; // entry[i] == 0일 때 i번 건물 짓기 가능
vector<int> g[MAX + 1];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N, M, K;
    cin >> N >> M >> K;

    while(M--) {
        int u, v;
        cin >> u >> v;

        g[u].push_back(v);
        entry[v]++;
    }

    int ans = 1;
    while(ans && K--) {
        int c, n;
        cin >> c >> n;

        if(c == 1) {
            if(entry[n] > 0) ans = 0;
            if(built[n]++ > 0) continue;

            for(auto e: g[n]) {
                entry[e]--;
            }
        } else if(c == 2) {
            if(built[n] <= 0) ans = 0;
            if(--built[n] > 0) continue;

            for(auto e: g[n]) {
                entry[e]++;
            }
        }
    }

    cout << (ans ? "King-God-Emperor" : "Lier!");

    return 0;
}