#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N, M;
    cin >> N >> M;

    if(M <= N) {
        if(M == 1 || M == 2) {
            cout << "NEWBIE!";
        } else {
            cout << "OLDBIE!";
        }
    } else {
        cout << "TLE!";
    }

    return 0;
}