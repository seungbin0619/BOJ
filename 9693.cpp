#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N, T = 0, M, t = 0;
    while(1) {
        cin >> N;
        if(N == 0) break;

        t = 0, M = 0;
        do {
            int k = t;
            while(k > 1 && k % 5 == 0) {
                k /= 5;
                M++;
            }
            t += 5;
        } while(t <= N);

        cout << "Case #" << ++T << ": " << M << '\n';
    }

    return 0;
}