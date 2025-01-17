#include <iostream>
#include <deque>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N, cmd;
    string s;
    cin >> N;
    deque<int> dq;

    while(N--) {
        cin >> s;
        if(s == "push") {
            cin >> cmd;
            dq.push_back(cmd);
        } else if(s == "pop") {
            if(dq.size()) {
                cout << dq.front() << '\n';
                dq.pop_front();
            } else {
                cout << -1 << '\n';
            }
        } else if(s == "size") {
            cout << dq.size() << '\n';
        } else if(s == "empty") {
            cout << dq.empty() << '\n';
        } else if(s == "front") {
            cout << (dq.size() ? dq.front() : -1) << '\n';
        } else if(s == "back") {
            cout << (dq.size() ? dq.back() : -1) << '\n';
        }
    }

    return 0;
}