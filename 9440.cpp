#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, A[14];
    while(1) {
        cin >> n;
        if(n == 0) return 0;

        int zero = 0;
        for(int i = 0; i < n; i++) {
            cin >> A[i];

            zero += A[i] == 0;
        }

        sort(A, A + n);
        queue<int> q;
        for(int i = zero; i < n; i++) {
            q.push(A[i]);

            if(q.size() >= 2) {
                while(zero-- > 0) {
                    q.push(0);
                }
            }
        }

        int ans[2] = { 0, };
        while(q.size()) {
            int f = q.size() % 2;
            ans[f] *= 10;
            ans[f] += q.front();
            q.pop();
        }

        cout << ans[0] + ans[1] << '\n';
    }

    return 0;
}

/*


1 2 7 8 9
2 2 2 2 3 4
0 0 1 1 2 2 3 3 4

1 7 9
2 8

223
224

10234
 1023

*/