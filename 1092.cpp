#include <bits/stdc++.h>
using namespace std;

int l[50], p[50];
int w[10000], ok[10000];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N, M, ans = 0;
    cin >> N;
    for(int i = 0; i < N; i++) {
        cin >> l[i];
        l[i] *= -1;
    }

    cin >> M;
    for(int i = 0; i < M; i++) {
        cin >> w[i];
        w[i] *= -1;
    }

    sort(l, l + N);
    sort(w, w + M);

    if(l[0] > w[0]) {
        cout << -1;
        return 0;
    }

    // -9 -8 -6
    // -7 -5 -4 -2 -2
    int cnt = 0;
    for(int i = 0; i < N; i++) {
        p[i] = lower_bound(w + p[i], w + M, l[i]) - w;
    }

    while(cnt < M) {
        for(int i = 0, j; i < N; i++) {
            j = p[i];
            while(j < M && ok[j]) j++;
            if(j >= M) continue;

            ok[j] = 1;
            p[i] = j;
            cnt++;
        }

        ans++;
    }
    
    cout << ans;

    return 0;
}