#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll v[] {
    202021,
    20202021,
    202002021,
    202012021,
    202022021,
    202032021,
    202042021,
    202052021,
    202062021,
    202072021,
    202082021,
    202092021
}; // 12

ll solve() {
    ll ans = 0, n, A[100000];
    unordered_map<ll, ll> m;

    cin >> n;
    for(ll i = 0; i < n; i++) {
        cin >> A[i];
        m[A[i]]++;
    }

    for(ll i = 0; i < n; i++) {
        for(auto j: v) {
            if(m.count(j - A[i]) == 0) continue;
            
            ans += m[j - A[i]];
        }
    }

    return ans >> 1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int T;
    cin >> T;

    while(T--) {
        cout << solve() << '\n';
    }

    return 0;
}