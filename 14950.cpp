#include <bits/stdc++.h>
#define MAX 30000
using namespace std;
using pi = pair<int, int>;

struct Edge {
    int u, v, t;
    bool operator<(const Edge& e) {
        return t < e.t;
    }
};

Edge e[MAX];
int s[10001];

int _find(int a) {
    if(s[a] != a) 
        s[a] = _find(s[a]);
    return s[a];
}

void _union(int a, int b) {
    int fa = _find(a);
    int fb = _find(b);
    
    if(fa == fb) return;
    
    if(fa > fb) s[fa] = fb;
    else s[fb] = fa;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N, M, t;
    cin >> N >> M >> t;

    for(int i = 1; i <= N; i++) s[i] = i;

    for(int i = 0; i < M; i++) {
        cin >> e[i].u >> e[i].v >> e[i].t;
    }

    sort(e, e + M);

    int ans = 0;
    for(int i = 0, j = 0, u, v, c; i < M && j < N - 1; i++) {
        u = e[i].u;
        v = e[i].v;
        c = e[i].t;
        
        if(_find(u) == _find(v)) continue;

        _union(u, v);
        ans += c + t * j++;
    }

    cout << ans;

    return 0;
}