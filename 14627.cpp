#include <bits/stdc++.h>
#define MAX 1000000
using namespace std;
using ll = long long;

ll S, C;
ll L[MAX];

ll get_l() {
    ll s = 1, e = 1e9, m;

    while(s <= e) {
        m = (s + e) >> 1;
        
        ll c = 0;
        for(ll i = 0; i < S; i++) {
            c += L[i] / m;
        }

        if(c >= C) s = m + 1;
        else e = m - 1;
    }

    return e;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    ll ans = 0;
    cin >> S >> C;

    for(ll i = 0; i < S; i++) {
        cin >> L[i];
        
        ans += L[i];
    }

    cout << ans - get_l() * C;

    return 0;
}