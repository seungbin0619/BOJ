#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int ans = 1;
    string S;
    cin >> S;

    for(auto c: S)
        ans += c == ',';

    cout << ans;

    return 0;
}