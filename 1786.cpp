#include <bits/stdc++.h>
#define MAX 1000000
using namespace std;

int dp[MAX], kmp[MAX];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int ans = 0;
    queue<int> q;

    string T, P;
    getline(cin, T);
    getline(cin, P);

    for(int i = 1, j = 0; i < P.size(); i++) {
        if(P[i] == P[j]) {
            kmp[i] = j + 1;
            j++;
        } else if(j > 0) {
            j = kmp[j - 1];
            i--;
        } else kmp[j] = 0;
    }

    // kmp = 0 0 1
    for(int i = 0, j = 0; i < T.size(); i++) {
        while(j && T[i] != P[j])
            j = kmp[j - 1];

        if(T[i] == P[j]) {
            j++;
            if(j == P.size()) {
                ans++;
                q.push(i - j + 2);
                j = kmp[j - 1];
            }
        }
    }

    cout << ans << '\n';
    while(q.size()) {
        cout << q.front() << ' ';
        q.pop();
    }

    return 0;
}