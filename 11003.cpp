#include <bits/stdc++.h>
#define MAX 5000000
using namespace std;

int A[MAX];

struct comp {
    bool operator()(const int& a, const int& b) {
        return A[a] > A[b];
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N, L;
    cin >> N >> L;

    priority_queue<int, vector<int>, comp> pq;

    for(int i = 0; i < N; i++) {
        cin >> A[i];
        while(pq.size() && pq.top() < i - L + 1)
            pq.pop();
        pq.push(i);

        cout << A[pq.top()] << ' ';
    }

    return 0;
}