#include <iostream>
#include <deque>
#include <stack>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, cmd, last;
    char c;
    deque<char> dq;
    stack<int> s;

    cin >> N;
    while(N--) {
        cin >> cmd;

        if(cmd == 1) {
            cin >> c;
            dq.push_back(c);
            s.push(cmd);
        } else if(cmd == 2) {
            cin >> c;
            dq.push_front(c);
            s.push(cmd);
        } else if(dq.size()) {
            if(s.top() == 1) {
                dq.pop_back();
            } else {
                dq.pop_front();
            }

            s.pop();
        }
    }

    if(!dq.size())  cout << '0';
    while(dq.size()) {
        cout << dq.front();
        dq.pop_front();
    }

    return 0;
}