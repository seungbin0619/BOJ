#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N;
    cin >> N;

    // 1 -> 4 -> 16

    for(int i = 1; i <= 100; i++) {
        if(1 + i + i * i == N) {
            cout << i;
            break;
        }
    }

    return 0;
}