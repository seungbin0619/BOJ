#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    ll N;
    cin >> N;

    if(N % 2 == 0 || N % 5 == 0) {
        cout << -1;
        return 0;
    }

    for(int i = 1, j = 0;; i++) {
        j = (j * 10 + 1) % N;

        if(j == 0) {
            cout << i;
            break;
        }
    }

    return 0;
}