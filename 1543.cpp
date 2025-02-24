#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    string s, f;
    getline(cin, s);
    getline(cin, f);

    int ans = 0;
    for(int i = 0; i < s.size(); i++) {
        for(int j = 0; i + j < s.size() && j < f.size(); j++) {
            if(s[i + j] != f[j]) break;
            if(j < f.size() - 1) continue;

            i += j;
            ans++;
        }
    }

    cout << ans;

    return 0;
}