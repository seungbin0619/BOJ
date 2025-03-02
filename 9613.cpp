#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll gcd(ll a, ll b) {
    if(b == 0) return a;
    else return gcd(b, a % b);
}

void solve() {
    ll n, A[100], ans = 0;
    cin >> n;
    for(ll i = 0; i < n; i++) {
        cin >> A[i];

        for(ll j = 0; j < i; j++) {
            ans += gcd(A[i], A[j]);
        }
    }

    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    ll t;
    cin >> t;
    while(t--) {
        solve();
    }

    return 0;
}