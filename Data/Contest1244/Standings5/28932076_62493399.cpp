#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

#define int ll
#define loop(i, n) for(int i = 0; i < (int)n; ++i)
#define loop1(i, n) for(int i = 1; i <= (int)n; ++i)
#define fi first
#define sec second
#define pb push_back
#define pi pair <int, int>
#define len length()

const int N = 1e5 + 7;

vector <int> g[N];
int cost[4][N], ans;

void cnt_ans(int v, int p, pi last, bool f) {
    if (last.fi + last.sec == 1) {
        if (!f)
            ans += cost[2][v];
        else
            cost[3][v] = 3;
        last = {last.sec, 2};
    }
    else if (last.fi + last.sec == 2) {
        if (!f)
            ans += cost[1][v];
        else
            cost[3][v] = 2;
        last = {last.sec, 1};
    }
    else {
        if (!f)
            ans += cost[0][v];
        else
            cost[3][v] = 1;
        last = {last.sec, 0};
    }
    for (int u : g[v])
        if (u != p)
            cnt_ans(u, v, last, f);
}

void solve() {
    int n;
    cin >> n;
    loop(i, 3)
        loop1(j, n)
            cin >> cost[i][j];
    loop(i, n - 1) {
        int u, v;
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    int f = 0;
    loop1(v, n) {
        if (g[v].size() > 2) {
            cout << "-1";
            return;
        }
        if (g[v].size() == 1)
            f = v;
    }
    int ff = g[f][0], fff = (g[ff][0] == f ? g[ff][1] : g[ff][0]);
    //cerr << ff << " " << fff << "\n";
    int arr[6], c = 0;
    loop(i, 3)
        loop(j, 3) {
            if (j == i)
                continue;
            cnt_ans(fff, ff, {i, j}, 0);
            //cerr << i << " " << j << "\n";
            ans += cost[i][f];
            ans += cost[j][ff];
            arr[c] = ans;
            ans = 0;
            ++c;
        }
    /*loop(i, 6)
        cerr << arr[i] << " ";
    cerr << "\n";*/
    int m = 0;
    loop(i, 6)
        if(arr[i] < arr[m])
            m = i;
    c = 0;
    loop(i, 3)
        loop(j, 3) {
            if (j == i)
                continue;
            if (c == m) {
                //cerr << c << " ";
                cnt_ans(fff, ff, {i, j}, 1);
                cost[3][f] = i + 1;
                cost[3][ff] = j + 1;
            }
            ++c;
        }
    cout << arr[m] << "\n";
    loop1(i, n)
        cout << cost[3][i] << " ";
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}
