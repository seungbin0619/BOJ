#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    double W, H, N, d;
    cin >> W >> H >> N;

    double ans = 0;
    d = H / N; // 0.25
    for(double i = 1; i < N / 2; i++) {
        H -= d * 2;
        ans += H;
    }

    cout.precision(6);
    cout << fixed;
    cout << ans * 2;

    return 0;
}