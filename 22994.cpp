#include <bits/stdc++.h>
#define MAX 1000
using namespace std;

int n, m;
char board[MAX][MAX];

int gcd(int a, int b) {
    if(b == 0) return a;
    else return gcd(b, a % b);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n >> m;
    int i = n, j = m;

    for(int r = 0; r < n; r++) {
        for(int c = 0; c < m; c++) {
            cin >> board[r][c];
        }
    }

    for(int r = 0, k; r < n; r++) {
        k = 1;
        for(int c = 1; c < m; c++) {
            if(board[r][c] == board[r][c - 1]) {
                k++;
            } else {
                j = gcd(j, k);
                k = 1;
            }
        }
        j = gcd(j, k);
    }

    for(int c = 0, k; c < m; c += j) {
        k = 1;
        for(int r = 1; r < n; r++) {
            if(board[r][c] == board[r - 1][c]) {
                k++;
            } else {
                i = gcd(i, k);
                k = 1;
            }
        }
        i = gcd(i, k);
    }

    cout << (n / i) << ' ' << (m / j) << '\n';
    for(int r = 0; r < n; r += i) {
        for(int c = 0; c < m; c += j) {
            cout << board[r][c];
        } cout << '\n';
    }

    return 0;
}