#include <iostream>
#include <algorithm>
using namespace std;

int convert(int k, int o) {
    int ans = 0;
    int tmp = 1;

    while(k > 0) {
        if(k % 10 >= o) return 0;
        ans += (k % 10) * tmp;
        k /= 10;
        tmp *= o;
    }

    return ans;
}

void solve() {
    int T, K;
    cin >> T >> K;

    cout << T << ' ';
    cout << convert(K, 8) << ' ';
    cout << K << ' ';
    cout << convert(K, 16) << '\n';
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int T;
    cin >> T;
    while(T--) {
        solve();
    }

    return 0;
}