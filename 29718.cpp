#include <bits/stdc++.h>
#define MAX 2000
using namespace std;

int Q[MAX + 1];
int psum[MAX + 1];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N, M, A;
    cin >> N >> M;
    for(int i = 1; i <= N; i++) {
        for(int j = 1, q; j <= M; j++) {
            cin >> q;
            Q[j] += q;
        }
    }

    cin >> A;
    int ans = 0;

    for(int i = 1; i <= M; i++) {
        psum[i] = psum[i - 1] + Q[i];
        if(i >= A) 
            ans = max(ans, psum[i] - psum[i - A]);
    }


    cout << ans;

    return 0;
}