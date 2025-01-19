#include <bits/stdc++.h>
using namespace std;

struct Point {
    int r, c;

    Point operator+(const Point &p) {
        return { r + p.r, c + p.c };
    }

    bool operator==(const Point& p) {
        return r == p.r && c == p.c;
    }
};

int ans = 0, cnt;

int b[6][6];
int v[6][6];

Point d[4] = {
    { -1, 0 },
    { 0,  1 },
    { 1,  0 },
    { 0, -1 } 
};

bool can_move_to(Point p) {
    return p.r >= 1 && p.r <= 5 && p.c >= 1 && p.c <= 5;
}

bool check(Point p) {
    if(!can_move_to(p)) return false;
    if(b[p.r][p.c]) return false;
    if(v[p.r][p.c]) return false;

    return true;
}

void dfs(Point p1, Point p2) {
    v[p1.r][p1.c] = 1;
    v[p2.r][p2.c] = 1;
    cnt--;

    Point n1, n2;
    for(int i = 0; i < 4; i++) {
        n1 = p1 + d[i];
        if(!check(n1)) continue;

        for(int j = 0; j < 4; j++) {
            n2 = p2 + d[j];
            if(!check(n2)) continue;

            if(n1 == n2) {
                if(cnt == 0) ans++;
                continue;
            }

            dfs(n1, n2);
        }
    }

    cnt++;

    v[p1.r][p1.c] = 0;
    v[p2.r][p2.c] = 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int K;
    cin >> K;

    cnt = (25 - K) >> 1;
    while(K--) {
        int r, c;
        cin >> r >> c;

        b[r][c] = 1;
    }

    dfs({1, 1}, {5, 5});
    cout << ans;

    return 0;
}