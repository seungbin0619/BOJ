#include <bits/stdc++.h>
#define MOD 100
using namespace std;

int mask(int a, int b) {
    return (a << 8) + b;
}

void ans(int a) {
    if(a == 0) cout << "00";
    else if(a < 10) cout << "0" << a;
    else cout << a % 100;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int x, y, a0, a1, n, k, t0, t1;
    cin >> x >> y >> a0 >> a1 >> n;
    t0 = a0, t1 = a1;

    if(n == 0) {
        ans(a0);
        return 0;
    } else if(n == 0) {
        ans(a1);
        return 0;
    }

    unordered_map<int, int> m;
    for(int i = 0, tmp; i < 1000000; i++) {
        tmp = a1;

        a1 = x * a1 + y * a0;
        a1 %= 100;
        a0 = tmp;

        tmp = mask(a0, a1);
        if(m.count(tmp)) {
            k = i;
            break;
        }

        m[tmp] = i;
    }

    for(int i = 1, tmp; i < (n - 1) % k; i++) {
        tmp = a1;

        a1 = (x * a1 + y * a0) % 100;
        a0 = tmp;
    }

    ans(a1);

    return 0;
}