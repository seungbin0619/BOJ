#include <bits/stdc++.h>
#define MAX 100
using namespace std;

int A[MAX];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N, ans = 0;
    cin >> N;
    for(int i = 0; i < N; i++) {
        cin >> A[i];
    }

    for(int i = N - 2; i >= 0; i--) {
        while(A[i] >= A[i + 1]) {
            A[i]--;
            ans++;
        }
    }

    cout << ans;

    return 0;
}