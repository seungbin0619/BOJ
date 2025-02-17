#include <bits/stdc++.h>
#define MAX 300000
using namespace std;
using ll = long long;

unordered_set<ll> chk;
unordered_map<ll, ll> L, R;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    ll n, q, l, r;
    cin >> n;

    for(int i = 0; i < n; i++) {
        cin >> l >> r;
        chk.insert(l * 1e7 + r);

        // R, L은 각각 r 혹은 l로 끝나는 값 중 구간이 가장 큰 값
        L[l] = max(L[l], r - l);
        R[r] = max(R[r], r - l);
    }

    // 답은 -1, 1, 2중 1개
    cin >> q;
    for(int i = 0; i < q; i++) {
        cin >> l >> r;
        if(chk.count(l * 1e7 + r)) cout << 1 << '\n';
        else if(L[l] >= r - l && R[r] >= r - l) cout << 2 << '\n';
        else cout << -1 << '\n';
    }

    return 0;
}