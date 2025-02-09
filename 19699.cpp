#include <bits/stdc++.h>
#define MAX 9
using namespace std;

int N, M;
int prime[50001];
int H[MAX], visited[MAX];
unordered_set<int> s;

void dfs(int k, int depth) {
    if(depth == 0) {
        s.insert(k);
        return;
    }

    for(int i = 0; i < N; i++) {
        if(visited[i]) continue;

        visited[i] = true;
        dfs(k + H[i], depth - 1);
        visited[i] = false;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;

    for(int i = 0; i < N; i++) {
        cin >> H[i];
    }

    dfs(0, M);

    for(int i = 2; i <= 50000; i++) prime[i] = 1;
    for(int i = 2; i <= 50000; i++) {
        if(!prime[i]) continue;
        for(int j = i + i; j <= 50000; j += i) {
            prime[j] = 0;
        }
    }

    vector<int> v;
    for(auto i: s) {
        if(!prime[i]) continue;
        v.push_back(i);
    }

    if(v.size() == 0) {
        cout << -1;
        return 0;
    }

    sort(v.begin(), v.end());
    for(auto i: v) {
        cout << i << ' ';
    }

    return 0;
}