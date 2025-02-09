#include <bits/stdc++.h>
#define MAX 1e9
using namespace std;
using ll = long long;
using ull = unsigned long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    ll N;
    cin >> N;

    ll imax, imin, dmax, dmin;
    imax = dmax = MAX * -2;
    imin = dmin = MAX * 2;

    for(ll i = 0, x, y; i < N; i++) {
        cin >> x >> y;

        imax = max(imax, x - y);
        imin = min(imin, x - y);
        dmax = max(dmax, x + y);
        dmin = min(dmin, x + y);
    }

    ull k = (ull)max(dmax - dmin, imax - imin);
    
    cout << fixed;
    cout.precision(1);
    cout << k * k / 2;

    if(k % 2) cout << ".5";

    return 0;
}