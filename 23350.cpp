#include <bits/stdc++.h>
#define MAX 100
using namespace std;

int P[MAX + 1], W[MAX + 1];
int cnt[MAX + 1];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N, M, ans = 0, n;
    queue<int> q;
    stack<int> s1, s2;

    cin >> N >> M;
    for(int i = 0; i < N; i++) {
        cin >> P[i] >> W[i];
        cnt[P[i]]++;
    
        q.push(i);
    }

    while(q.size()) {
        while(cnt[M] < 1) {
            while(s1.size()) s1.pop();
            M--;
        }

        if(M < 1) break;
        n = q.front(); q.pop();
        
        if(P[n] == M) { // 낮은 우선순위
            while(s1.size() && W[s1.top()] < W[n]) {
                ans += W[s1.top()];
                s2.push(s1.top()); s1.pop();
            }

            ans += W[n];
            s1.push(n);

            while(s2.size()) {
                ans += W[s2.top()];
                s1.push(s2.top()); s2.pop();
            }

            cnt[M]--;
        } else { 
            ans += W[n];
            q.push(n);
        }
    }

    cout << ans;

    return 0;
}