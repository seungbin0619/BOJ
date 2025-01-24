#include <bits/stdc++.h>
using namespace std;

int A[1000];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N, M, K;
    cin >> N >> M >> K;
    for(int i = 0; i < N; i++) {
        cin >> A[i];
        A[i] *= -1;
    }

    int ans = 0, target = M * K;
    sort(A, A + N);
    while(ans < N && target > 0) {
        target += A[ans++];
    }

    if(target > 0) cout << "STRESS";
    else cout << ans;

    return 0;
}