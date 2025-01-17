#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

struct Team {
    int idx;
    int ac;
    int wa[16];
    int tm[16];
    int T;

    bool operator<(const Team& x) {
        if(ac == x.ac) 
            if(T == x.T) return idx < x.idx;
            else return T < x.T;
        return ac > x.ac;
    }
};

Team teams[101];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m, q;
    cin >> n >> m >> q;

    string ret;
    for(int i = 0; i < n; i++) {
        teams[i].idx = i + 1;
        for(int j = 1; j <= m; j++) {
            teams[i].tm[j] = -1;
        }
    }

    for(int i = 0, tm, t, idx; i < q; i++) {
        cin >> tm >> t >> idx >> ret;
        t--;

        if(ret != "AC") {
            teams[t].wa[idx]++;
            continue;
        }
        if(teams[t].tm[idx] != -1) continue;

        teams[t].ac++;
        teams[t].tm[idx] = tm + teams[t].wa[idx] * 20;
    }

    for(int i = 0; i < n; i++) {
        for(int j = 1; j <= m; j++) {
            if(teams[i].tm[j] < 0) continue;
            teams[i].T += teams[i].tm[j];
        }
    }

    sort(teams, teams + n);

    for(int i = 0; i < n; i++) {
        cout << teams[i].idx << ' ';
        cout << teams[i].ac << ' ';
        cout << teams[i].T << '\n';
    }

    return 0;
}