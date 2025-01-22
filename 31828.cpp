#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;

int ans[100001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N;
    cin >> N;

    ans[4] = 1;

    /*

    i = 4(MRDR), ans = 1
    1 2 3 4 5 6 7 8 9 ... 26 <- 같은 것의 개수
    1 2 
    dp[i][?]

    i = 5, ans = 126

    M R _ D R // 5C4 * 26

    i = 6, ans = ?

    _ M R _ D R // 6C4 * 26 * 26

     */
    

    cout << ans[N];

    return 0;
}