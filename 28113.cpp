#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, a, b;
    cin >> n >> a >> b;

    if(a == b) {
        cout << "Anything";
    } else if(a < b) {
        cout << "Bus";
    } else cout << "Subway";

    return 0;
}