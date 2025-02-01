#include <bits/stdc++.h>
#define MAX 100000
using namespace std;
using pi = pair<int, int>;

int L[MAX + 1];
int ans[MAX + 1], m[MAX + 1];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N;
    cin >> N;
    for(int i = 1; i <= N; i++) {
        cin >> L[i];
        m[i] = 1e5 + 1;
    }

    /* 자기보다 큰 건물만 볼 수 있다.
    
    ...
    .......
    .
    ......
    ...
    .....
    .
    .......

    left  : 0, 0, 1, 1, 2, 2, 3, 0 
    right : 1, 0, 2, 1, 2, 1, 1, 0
    sum   : 1. 0, 3, 2, 4, 3, 4, 0
    
     */

    stack<int> s;
    for(int i = 1; i <= N; i++) {
        while(s.size() && L[s.top()] <= L[i]) {
            s.pop();
        }

        ans[i] = s.size();
        if(s.size()) m[i] = s.top();

        s.push(i);
    }
    
    while(s.size()) s.pop();

    for(int i = N; i > 0; i--) {
        while(s.size() && L[s.top()] <= L[i]) {
            s.pop();
        }

        ans[i] += s.size();
        if(s.size()) {
            if(m[i] == 0) m[i] = s.top();
            else if(abs(i - m[i]) == abs(s.top() - i)) {
                m[i] = min(m[i], s.top());
            } else if(abs(i - m[i]) > abs(s.top() - i)) {
                m[i] = s.top();
            }
        }

        s.push(i);
    }

    for(int i = 1; i <= N; i++) {
        cout << ans[i];
        if(ans[i]) cout << ' ' << m[i];
        cout << '\n';
    }

    return 0;
}