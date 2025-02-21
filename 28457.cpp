#include <bits/stdc++.h>
using namespace std;
using pi = pair<int, int>;

enum tiletype {
    normal = 0,
    start,
    land,
    welfare,
    space,
    goldkey,
};

using tt = tiletype;

class OnesMarble {
private:
    int _size;
    int _position;
    int _money;
    int _salary; // 월급
    int _welfare;
    int _land;
    int _lcount;
    bool _lose = false;

    tt _type[40];
    bool _buy[40] = { 0, };
    int _cost[40] = { 0, };

    queue<pi> _gold_keys;
public:
    OnesMarble(int n, int S, int W, int G) {
        _size = n * 4 - 4;
        _lcount = _size - 4 - G;
        _money = S;
        _salary = W;
        _position = 0;
        _welfare = 0;
        _land = 0;
        _lose = 0;

        for(int i = 0, c, x; i < G; i++) {
            cin >> c >> x;
            add_gold_key(c, x);
        }

        _type[0] = tt::start;
        _type[n - 1] = tt::land;
        _type[n * 2 - 2] = tt::welfare;
        _type[n * 3 - 3] = tt::space;
        
        for(int i = 0, p; i < _size; i++) {
            if(i % (n - 1) == 0) continue;

            char t;
            cin >> t;
            if(t == 'G') {
                _type[i] = tt::goldkey;
            } else if(t == 'L') {
                cin >> p;
                _cost[i] = p;
            }
        }
    }

    void add_gold_key(int c, int x) {
        _gold_keys.push( { c, x } );
    }

    void move(int d1, int d2) {
        switch(_type[_position]) {
            case tt::land:
                if(_land-- > 0) {
                    if(d1 == d2) _land = 0;
                    return;
                }

                break;
            case tt::space:
                _position = 0;
                earn_money(_salary);

                break;
        }

        int next = _position + d1 + d2;
        end(next);
    }

    void earn_money(int earned) {
        _money += earned;

        _lose |= _money < 0;
    }
    
    void end(int next) {
        if(next >= _size) {
            int cnt = next / _size;
            earn_money(_salary * cnt);

            next %= _size;
        }

        _position = next;

        switch(_type[next]) {
            case tt::normal:
                if(_buy[next]) break;
                if(_money < _cost[next]) break;

                _money -= _cost[next];
                _buy[next] = true;
                _lcount--;

                break;
            case tt::goldkey:
                int c, x;
                c = _gold_keys.front().first;
                x = _gold_keys.front().second;
                _gold_keys.push(_gold_keys.front());
                _gold_keys.pop();

                if(c == 1) {
                    earn_money(x);
                } else if(c == 2) {
                    earn_money(-x);
                } else if(c == 3) {
                    earn_money(-x);
                    _welfare += x;
                } else if(c == 4) {
                    move(x, 0);
                }

                break;
            case tt::welfare:
                earn_money(_welfare);
                _welfare = 0;

                break;
            case tt::land:
                if(_land) return;
                _land = 3;

                break;
        }
    }

    bool win() {
        return !_lose && _lcount <= 0;
    }

    bool lose() {
        return _lose;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, S, W, G, I, d1, d2;
    cin >> n >> S >> W >> G;

    auto board = new OnesMarble(n, S, W, G);

    cin >> I;
    while(I-- > 0 && !board->lose()) {
        cin >> d1 >> d2;

        board->move(d1, d2);
    }

    cout << (board->win() ? "WIN" : "LOSE");

    return 0;
}