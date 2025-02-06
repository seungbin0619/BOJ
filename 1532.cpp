#include <bits/stdc++.h>
using namespace std;

int a[3], b[3], ans;

bool check() {
    for(int i = 0; i < 3; i++) {
        if(a[i] < b[i]) return false;
    }
    return true;
}

// n번 동전을 k개 만드는 함수
bool make(int n, int k) {
    if(k < 1) return true; // 안 만들어도 됨.
    if(n > 1) return false; // 동화는 못만듬

    int t = k * 11; // n + 1번 동전이 k * 9개 필요함

    if(a[n + 1] < t && !make(n + 1, t - a[n + 1]))
        return false;

    a[n] += k;
    ans += k;
    a[n + 1] -= t;

    return true;
}

// n번 동전을 k개 만드는 함수
bool revmake(int n, int k) {
    if(k < 1) return true;
    if(n == 0) return false;

    int t = (k + 8) / 9; 
    // n - 1번 동전이 (k + 8) / 9개 필요함.
    // 1 ~ 9 -> 1개, 10 ~ 18 -> 2개...

    if(a[n - 1] < t && !revmake(n - 1, t - a[n - 1]))
        return false;

    a[n] += 9 * t;
    a[n - 1] -= t;
    ans += t;

    return true;
}

int solve() {
    // 우선순위: 금화 > 동화 > 은화
    if(!make(0, b[0] - a[0])) return -1;
    if(!revmake(2, b[2] - a[2])) return -1;

    // 은화는 어떡하나!
    int t = b[1] - a[1]; // 부족한 은화 수.
    while(a[0] > b[0] && a[1] < b[1]) {
        a[0]--;
        a[1] += 9;
        ans++;

    }

    while(a[2] - 11 >= b[2] && a[1] < b[1]) {
        a[2] -= 11;
        a[1] += 1;
        ans++;
    }

    if(check()) return ans;
    else return -1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> a[0] >> a[1] >> a[2];
    cin >> b[0] >> b[1] >> b[2];

    cout << solve();

    return 0;
}