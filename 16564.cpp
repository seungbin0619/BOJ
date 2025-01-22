#include <bits/stdc++.h>
using namespace std;

unordered_map<int, int> m;
int l[1000000];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N, K, r = 0, i, j, ans = 0;
    cin >> N >> K;

    for(i = 0, j; i < N; i++) {
        cin >> j;
        if(m.count(j)) m[j]++;
        else {
            m[j] = 1;
            l[r++] = j;
        }
    }

    sort(l, l + r);

    i = 0;
    while(K > 0) {
        if(i >= r - 1) {
            ans = l[i] + K / m[l[i]];
            break;
        }

        // i < r
        int next = l[i + 1] - l[i]; // 올려야하는 레벨 수
        int need = next * m[l[i]]; // 필요한 레벨합

        if(need > K) { // 부족하면
            ans = l[i] + K / m[l[i]];

            break;
        } else {
            ans = l[i + 1];
            K -= need;
            
            m[l[i + 1]] += m[l[i]];
            m[l[i]] = 0;

            i++;
        }
    }

    cout << ans;

    return 0;
}

/*
10 15 20


*/