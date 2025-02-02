#include <bits/stdc++.h>
#define MAX 200000
using namespace std;
using pi = pair<int, int>;

struct Circle {
    int k, x, r;

    bool operator<(const Circle& c) {
        return x + r < c.x + c.r;
    }
};

int N;
Circle C[MAX + 1];
int parent[MAX + 1];
int v[MAX + 1];

// C[a]가 C[b]에 포함되어잇는가
bool isContained(int a, int b) {
    int ax, ar, bx, br;

    ax = C[a].x;
    ar = C[a].r;
    bx = C[b].x;
    br = C[b].r;

    return (ax - ar > bx - br) && (ax + ar < bx + br);
}

void init_parent() {
    stack<int> s;

    for(int i = 1; i <= N; i++) {
        while(s.size() && isContained(s.top(), i)) {
            parent[s.top()] = i;
            s.pop();
        }

        s.push(i);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> N;

    C[0] = { 0, 0, (int)1e7 };
    for(int i = 1, k, x, r; i <= N; i++) {
        cin >> k >> x >> r;
        C[i] = { k, x, r };
    }

    sort(C + 1, C + N + 1);

    /* 

    after sorting
    0 0 1000000000

    2 3 1
    3 6 1
    1 5 4
    4 13 3

     */

    init_parent();

    int a, b, A, B;
    cin >> a >> b;
    for(int i = 1; i <= N; i++) {
        if(C[i].k == a) A = i;
        if(C[i].k == b) B = i;
    }

    //cout << C[A].k << ' ' << C[B].k << '\n';
    queue<int> q;
    stack<int> s;

    q.push(A); s.push(B);
    v[A] = a = 1;
    while(A) {
        A = parent[A];
        v[A] = ++a;
        q.push(A);
    }

    while(B) {
        if(v[B]) {
            a = v[B];
            break;
        }

        B = parent[B];
        s.push(B);
    }

    cout << a + s.size() - 1 << '\n';

    while(q.size() && q.front() != s.top()) {
        cout << C[q.front()].k << ' ';
        q.pop();
    }

    while(s.size()) {
        cout << C[s.top()].k << ' ';
        s.pop();
    }

    return 0;
}