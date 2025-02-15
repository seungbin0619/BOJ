#include <bits/stdc++.h>
using namespace std;
using pi = pair<int, int>;

int N;
pi ans;
bool v[10], valid;

void bt(int n) {
    if(n > N) return;
    if(valid) return;

    int k = N - n, tmp = k;
    if(k > 0 && n > 0) {
        int visited[10] = { 0, };
        while(tmp > 0) {
            if(v[tmp % 10]) break;
            if(visited[tmp % 10]++ > 0) break;

            tmp /= 10;
        }

        if(tmp == 0) {
            ans = { k, n };
            valid = 1;

            return;
        }
    }

    for(int i = 0; i < 10; i++) {
        if(v[i]) continue;
        v[i] = 1;
        bt(n * 10 + i);
        v[i] = 0;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> N;
    for(int i = 1; i < 10; i++) {
        v[i] = 1;
        bt(i);
        v[i] = 0;
    }

    if(!valid) cout << -1;
    else cout << ans.first << " + " << ans.second;

    return 0;
}