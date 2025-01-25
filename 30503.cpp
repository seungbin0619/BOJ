#include <bits/stdc++.h>
#define MAX 1000
using namespace std;

int A[MAX + 1];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N, Q;
    cin >> N;
    for(int i = 1; i <= N; i++)
        cin >> A[i];

    cin >> Q;
    while(Q--) {
        int cmd, l, r, k;
        cin >> cmd >> l >> r;
        if(cmd == 1) {
            cin >> k;
            int ans = 0;
            for(int i = l; i <= r; i++) {
                ans += k == A[i];
            }
            cout << ans << '\n';
        }
        else {
            for(int i = l; i <= r; i++) {
                A[i] = 0;
            }
        }
    }

    return 0;
}