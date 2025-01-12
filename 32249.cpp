#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int N, M;
char b[2][11][1000001];
int cnt[2][11];

/*
BAA(1) BAB(1)
ABA(1) BBA(1)

BAA(1) BBB(0)
AAA(0) BBA(1)

BAA(1) BBB(0)
AAB(1) ABA(2)

*/

int check() {
    int t[2] = { 0, 0 };
    for(int i = 0; i < 2; i++) {
        for(int j = 1; j <= N; j++) {
            if(j == N) {
                t[i] += max(1, cnt[i][j]);
            } else {
                t[i] += cnt[i][j];
            }
        }
    }

    return t[0] > t[1];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    string names[2] = {"Alice", "Bob"};

    int Q, t;
    char c;

    cin >> N >> M;
    for(int t = 0; t < 2; t++) {
        for(int r = 1; r <= N; r++) {
            for(int c = 1; c <= M; c++) {
                cin >> b[t][r][c];
                cnt[t][r] += b[t][r][c] == 'B' - t;
            }
        }
    }
    
    cout << names[check()] << '\n';

    cin >> Q;
    for(int q = 0, r0, c0, r1, c1; q < Q; q++) {
        cin >> r0 >> c0 >> r1 >> c1;
        //swap
        cnt[0][r0] -= b[0][r0][c0] == 'B';
        cnt[1][r1] -= b[1][r1][c1] == 'A';

        swap(b[0][r0][c0], b[1][r1][c1]);

        cnt[0][r0] += b[0][r0][c0] == 'B';
        cnt[1][r1] += b[1][r1][c1] == 'A';

        cout << names[check()] << '\n';
    }

    return 0;
}