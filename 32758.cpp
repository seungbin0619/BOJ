#include <bits/stdc++.h>
#define MAX 100000
using namespace std;
using ll = long long;

ll N[MAX], A[MAX];

ll solve(ll n, ll a) {
    // n + 1행사 중일 때, a개 얻기 위해 사야하는 개수
    if(a <= n) return a;
    if(n == 1) return 1;

    ll s = 1, e = 1e9, m;

    while(s < e) {
        m = (s + e) >> 1;
        ll c = n + 1 + (m - n) * n / (n - 1);
        
        if(c < a) {
            s = m + 1;
        } else {
            e = m;
        }
    }

    return e;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    ll M;
    cin >> M;
    for(ll i = 0; i < M; i++) {
        cin >> N[i];
    }
    
    for(ll i = 0; i < M; i++) {
        cin >> A[i];
        cout << solve(N[i], A[i]) << ' ';
    }

    return 0;
}