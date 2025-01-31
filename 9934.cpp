#include <bits/stdc++.h>
using namespace std;

int A[2000], o, K, cnt;

void inorder(int n) {
    if(n > cnt) return;

    inorder(n * 2);
    A[n] = ++o;
    inorder(n * 2 + 1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> K;
    cnt = (1 << K) - 1;

    inorder(1);

    int input[2000];
    for(int i = 1; i <= cnt; i++) {
        cin >> input[i];
    } 

    int p = 1;
    for(int i = 1; i <= cnt; i++) {
        cout << input[A[i]] << ' ';
        if(i == (1 << p) - 1) {
            p++;
            cout << '\n';
        }
    }

    return 0;
}