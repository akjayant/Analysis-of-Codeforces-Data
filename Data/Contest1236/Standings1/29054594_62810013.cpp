#include <bits/stdc++.h>
#define ALL(s) (s).begin(), (s).end()
#define rALL(s) (s).rbegin(), (s).rend()
#define sz(s) (int)(s).size()
#define mp make_pair
#define sqr(s) ((s) * (s))
 
using namespace std;
 
typedef complex<int> point;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int MOD = 1e9 + 7;
int n, m, k;
set<int> s_x[100500], s_y[100500];
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    //freopen("input.txt", "r", stdin);
    cin >> n >> m >> k;
    for (int i = 0; i < k; i++) {
        int x, y;
        cin >> x >> y;
        s_x[x].insert(y);
        s_y[y].insert(x);
    }
    int last_down_y = m + 1, last_left_x = n + 1, last_up_y = 0, last_right_x = 0;
    ll cnt = 1;
    for (int x = 1, y = 1, turn = 0, i = 0; ; turn = (turn + 1) % 4, i++) { ///0 - right, 1 - down, 2 - left, 3 - up
        // /cout << x << " " << y << " " << turn << " " << cnt << endl;
        if (turn == 0) { ///right
            int _y;
            auto it = s_x[x].upper_bound(y);
            if (it == s_x[x].end())
                _y = last_down_y - 1;
            else
                _y = min(*it - 1, last_down_y - 1);
            if (y == _y && i != 0)
                break;
            cnt += _y - y;
            y = _y;
            last_right_x = x;
        }
        if (turn == 1) { ///down
            int _x;
            auto it = s_y[y].upper_bound(x);
            if (it == s_y[y].end())
                _x = last_left_x - 1;
            else
                _x = min(*it - 1, last_left_x - 1);
            if (x == _x && i != 0)
                break;
            cnt += _x - x;
            x = _x;
            last_down_y = y;
        }
        if (turn == 2) { ///left
            int _y;
            auto it = s_x[x].upper_bound(y);
            if (it == s_x[x].begin())
                _y = last_up_y + 1;
            else {
                it--;
                _y = max(*it + 1, last_up_y + 1);
            }
            if (y == _y && i != 0)
                break;
            cnt += y - _y;
            y = _y;
            last_left_x = x;
        }
        if (turn == 3) { ///up
            int _x;
            auto it = s_y[y].upper_bound(x);
            if (it == s_y[y].begin())
                _x = last_right_x + 1;
            else {
                it--;
                _x = max(*it + 1, last_right_x + 1);
            }
            if (x == _x && i != 0)
                break;
            cnt += x - _x;
            x = _x;
            last_up_y = y;
        }
    }
    if (cnt + k == 1LL * n * m)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
}
