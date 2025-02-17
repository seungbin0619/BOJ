#include <bits/stdc++.h>
#define MAX 100
using namespace std;
using pi = pair<int, int>;

int N;
int dr[8] = { -1, -1, 0, 1, 1, 1, 0, -1 };
int dc[8] = { 0, 1, 1, 1, 0, -1, -1, -1 };
int b[MAX][MAX], mine[MAX][MAX], chk[MAX][MAX];

// k == 1일 때는 지뢰 0개라는 뜻.
void update(int r, int c, int k) {
    mine[r][c] = k;

    for(int i = 0, nr, nc; i < 8; i++) {
        nr = r + dr[i];
        nc = c + dc[i];

        if(nr < 0 || nr >= N) continue;
        if(nc < 0 || nc >= N) continue;
        if(b[nr][nc] == -1) continue;

        if(k) b[nr][nc]--;
        chk[nr][nc]--;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int r, c, ans = 0;
    queue<pi> q;

    cin >> N;
    for(r = 0; r < N; r++) {
        for(c = 0; c < N; c++) {
            char d;
            cin >> d;
            
            mine[r][c] = -1;
            if(d == '#') {
                b[r][c] = -1;
                continue;
            }

            b[r][c] = d - '0';
            q.push( { r, c } );
        }
    }

    for(r = 0; r < N; r++) {
        for(c = 0; c < N; c++) {
            if(b[r][c] == -1) continue;
            for(int i = 0, nr, nc; i < 8; i++) {
                nr = r + dr[i];
                nc = c + dc[i];

                if(nr < 0 || nr >= N) continue;
                if(nc < 0 || nc >= N) continue;

                chk[r][c] += b[nr][nc] == -1;
            }
        }
    }

    while(q.size()) {
        r = q.front().first;
        c = q.front().second;
        q.pop();

        if(b[r][c] != 0 && chk[r][c] > b[r][c]) {
            q.push( { r, c } );
            continue;
        }

        for(int i = 0, nr, nc; i < 8; i++) {
            nr = r + dr[i];
            nc = c + dc[i];
    
            if(nr < 0 || nr >= N) continue;
            if(nc < 0 || nc >= N) continue;
            if(b[nr][nc] != -1) continue;
            if(mine[nr][nc] != -1) continue;

            update(nr, nc, b[r][c] > 0);
        }

        // for(int i = 0; i < N; i++) {
        //     for(int j = 0; j < N; j++) {
        //         if(b[i][j] == -1) {
        //             if(mine[i][j] == -1) cout << '?';
        //             else if(mine[i][j] == 0) cout << ' ';
        //             else cout << '*';
        //         }
        //         else cout << b[i][j];
        //     } cout << '\n';
        // }
    }

    for(r = 1; r < N - 1; r++) {
        for(c = 1; c < N - 1; c++) {
            ans += mine[r][c] != 0;
        }
    }

    cout << ans;

    return 0;
}