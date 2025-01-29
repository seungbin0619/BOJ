#include <bits/stdc++.h>
using namespace std;
using pi = pair<int, int>;

pi get_position(char c) {
    int order = c == '.' ? 15 : c - 'A';
    return { order / 4, order % 4 };
}

int D(char alpha, int r, int c) {
    pi p = get_position(alpha);

    return abs(r - p.first) + abs(c - p.second);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int ans = 0;
    string s;
    for(int i = 0; i < 4; i++) {
        cin >> s;
        for(int j = 0; j < 4; j++) {
            if(s[j] == '.') continue;
            ans += D(s[j], i, j);
        }
    }

    cout << ans;

    return 0;
}