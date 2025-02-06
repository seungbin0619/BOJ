#include <bits/stdc++.h>
#define MAX 1000000
using namespace std;

int kmp[MAX];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int L;
    string s;
    cin >> L;
    cin.ignore();
    getline(cin, s);
    for(int i = 1, j = 0; i < L; i++) {
        while(j > 0 && s[i] != s[j])
            j = kmp[j - 1];

        if(s[i] == s[j]) {
            kmp[i] = ++j;
        }
    }

    for(int i = 0; i < L; i++) {
        cout << kmp[i] << ' ';
    } cout << '\n';

    return 0;
}