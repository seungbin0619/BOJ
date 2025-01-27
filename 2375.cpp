#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pl = pair<ll, ll>;

ll evaluate(vector<pl> v, ll k) {
    ll ret = 0;
    for(auto i: v) {
        ret += abs(i.first - k) * i.second;
    }
    return ret;
}

ll f(vector<pl> v) {
    ll s =-1e6, e = 1e6, m;
    while(s < e) {
        m = (s + e) >> 1;
        if(evaluate(v, m) > evaluate(v, m + 1)) {
            s = m + 1;
        } else {
            e = m;
        }
    }

    return s;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    ll n, ax, ay;
    cin >> n;

    unordered_map<ll, ll> mx, my;

    for(ll i = 0, x, y, p; i < n; i++) {
        cin >> x >> y >> p;

        mx[x] += p;
        my[y] += p;
    }

    vector<pl> vx, vy;

    for(auto k: mx) vx.push_back( { k.first, k.second } );
    for(auto k: my) vy.push_back( { k.first, k.second } );

    sort(vx.begin(), vx.end());
    sort(vy.begin(), vy.end());



    cout << f(vx) << ' ' << f(vy);

    return 0;
}