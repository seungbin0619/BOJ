#include <bits/stdc++.h>
#define MAX 100000
using namespace std;
using pi = pair<int, int>;

int B[MAX];

bool comp(const pi& a, const pi &b) {
    return a.first > b.first;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N;
    cin >> N;

    unordered_map<int, int> m;
    int d = -1e9;

    for(int i = 0, a; i < N; i++) {
        cin >> a;
        m[a] = i;
    }

    for(int i = 0, b; i < N; i++) {
        cin >> b;
        d = max(d, m[b] - i);

        B[i] = b;
    }

    for(int i = 0; i < N; i++) {
        if(d != m[B[i]] - i) continue;
        cout << B[i] << ' ';
    }

    return 0;
}