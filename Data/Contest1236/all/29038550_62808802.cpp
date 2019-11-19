#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define pb push_back
#define mp make_pair

typedef pair<int, int> ii;

const int mod = 1e9 + 7;

const int inf = 1e9;

int add(int x, int y) {
    return (1ll * x + 1ll * y) % mod;
}

int del(int x, int y) {
    return ((1ll * x - 1ll * y) % mod + mod) % mod;
}

int mul(int x, int y) {
    return (1ll * x * 1ll * y) % mod;
}
#define int long long
const int N = 1e5 + 5;

vector<int> row[N], col[N];

int n, m, k, x, y, turn, hihi;
long long sum;
int init[N];
ii p[N];

signed main() {
    cin.tie(0), ios_base::sync_with_stdio(0);
    cin >> n >> m >> k;
    init[0] = m + 1; init[1] = n + 1, init[2] = 0, init[3] = 0;
    //0:đi sang phải
    //1:đi xuống
    //2:đi sang trái
    //3:đi lên
    int ok = 0;
    for(int i = 1; i <= k; i++) {
        cin >> p[i].fi >> p[i].se;
        if(p[i].fi == 1 && p[i].se == 2)
            ok = 1;
        row[p[i].fi].pb(p[i].se);
        col[p[i].se].pb(p[i].fi);
    }
    if(m == 1)
        ok = 1;
    sum = 1ll * n * m - 1ll * k;
    for(int i = 1; i <= N - 5; i++) {
        row[i].pb(m + 1); row[i].pb(0);
        col[i].pb(0); col[i].pb(n + 1);
        sort(row[i].begin(), row[i].end());
        sort(col[i].begin(), col[i].end());
    }
    sum--;
    x = 1, y = 1, turn = 0;
    while(1) {
        //mymap[{x, y}]++;
        if(sum == 0) break;
        //cout << sum << " " << x << " " << y << " " << init[0] << " " << init[1] << " " << init[2] << " " << init[3] << "\n";
        if(turn == 0) {//di sang phai
            int it = lower_bound(row[x].begin(), row[x].end(), y) - row[x].begin();
            int lim = min(row[x][it], init[0]) - 1;
            if(lim - y == 0)
                hihi++;
            sum -= (lim - y);
            y = lim;
            init[0] = lim;
            init[3] = x;
            turn = 1;
        }
        else if(turn == 1) {//di xuong
            int it = lower_bound(col[y].begin(), col[y].end(), x) - col[y].begin();
            int lim = min(col[y][it], init[1]) - 1;
            if(lim - x == 0)
                hihi++;
            sum -= (lim - x);
            x = lim;
            init[1] = lim;
            init[0] = y;
            turn = 2;
        }
        else if(turn == 2) {//di sang trai
            int it = lower_bound(row[x].begin(), row[x].end(), y) - row[x].begin() - 1;
            int lim = max(row[x][it], init[2]) + 1;
            if(y - lim == 0)
                hihi++;
            sum -= (y - lim);
            y = lim;
            init[2] = lim;
            init[1] = x;
            turn = 3;
        }
        else {//di len
            int it = lower_bound(col[y].begin(), col[y].end(), x) - col[y].begin() - 1;
            int lim = max(col[y][it], init[3]) + 1;
            if(x - lim == 0)
                hihi++;
            sum -= (x - lim);
            x = lim;
            init[3] = lim;
            init[2] = y;
            turn = 0;
        }
        if(ok) {
            hihi = 0;
            ok = 0;
        }
        if(hihi == 1) break;
    }
    if(sum == 0)
        cout << "Yes";
    else
        cout << "No";
}
