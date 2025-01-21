#include <bits/stdc++.h>
#define MAX 100000
using namespace std;
using ll = long long;

ll x[MAX + 2], p[MAX + 2], ps[MAX + 2], m[MAX + 2];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N, e = 0, ans = 0, flag = 0;
    cin >> N;

    for(int i = 1; i <= N; i++) {
        cin >> x[i] >> p[i];
        ps[i] = ps[i - 1] + p[i];
        m[i] = x[i] - ps[i - 1];

        if(!e && flag && m[i] < 0) e = i;
        if(!flag && m[i] < 0) flag = i;
    }
    if(!flag) flag = N + 1;
    if(!e) e = N + 1;

    for(int i = N - 1; i > 0; i--) {
        m[i] = min(m[i], m[i + 1]);
    }

    //cout << flag << ' ' << e << '\n';
    for(int i = 1; i <= flag; i++) {
        if(i == flag) {
            ans |= p[i] >= -m[e];
        } else {
            ans |= p[i] >= -m[e - 1];
        }
    }

    cout << (ans ? "Kkeo-eok" : "Zzz");

    return 0;
}

/*

10 3 - 0  0  -> pass
1 1  - 3  -2 -> pass or >= 2
10 2 - 4  7  -> pass <- 얘는 패스하면 안됨.
5 1  - 6  -1 -> pass or >= 1
-------------------------
10 2 - 6  4

*/