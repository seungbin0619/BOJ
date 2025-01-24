#include <bits/stdc++.h>
#define MAX 1000
using namespace std;

int p[MAX + 1];
int order[MAX + 1];
int n[MAX + 1][MAX + 1];

bool comp(const int& a, const int& b) {
    return p[a] > p[b];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int M, N, Q, k, i;
    cin >> M >> N >> Q;
    for(i = 1; i <= N; i++) {
        cin >> p[i];
        order[i] = i;
    }

    sort(order + 1, order + N + 1, comp);

    /*
    
    3 3 3

    1 4 3
    1 3 3
    1 2 3
    
    1개만 다르면 된다.
     */

    k = i = 1;
    for(int j = 0, ans; j < Q; j++) {
        cout << "? " << k << ' ' << order[i] << endl;
        cin >> ans;
        n[order[i]][ans] = 1;

        k++;
        i++;

        if(k > M) {
            k = 1;
        }

        if(i > N) {
            i = 1;
        } else if(p[order[i]] == 1) {
            i = 1;
        }
    }
    
    // 1 - 1 4 3 2
    // 2 - 1 2 3 3

    cout << "! ";
    for(i = 1; i <= N; i++) {
        if(p[i] == 1) cout << 1 << ' ';
        else {
            for(int j = 1; j <= p[i]; j++) {
                if(n[i][j]) continue;

                cout << j << ' ' ;
                break;
            }
        }
    } cout << endl;

    return 0;
}