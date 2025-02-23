#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    string s;
    int r, c;

    cin >> s;
    r = s.size();

    for(c = 1; c <= s.size(); c++) {
        if(s.size() % c) continue;
        if(s.size() / c > c) continue;

        r = s.size() / c;
        break;
    }

    /*
    koaski

    kak
    osi
    */
    for(int i = 0, j = 0; i < s.size(); i++, j += r) {
        cout << s[(j + j / s.size()) % s.size()];
    }

    return 0;
}