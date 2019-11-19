#include <bits/stdc++.h>

/*
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("-O3")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
*/

#define mp make_pair
#define ll long long
#define ld long double
#define pb push_back
#define fast_io ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define fs first
#define sc second
#define getfiles ifstream cin("input.txt"); ofstream cout("output.txt");
#define endl '\n'
#define con continue
#define pii pair<int, int>
#define all(x) x.begin(), x.end()

const int INF = 2000000005;
const ll BIG_INF = 2000000000000000005;
const int mod = 1000000007;
const int P = 31;
const ld PI = 3.141592653589793238462643;
const double eps = 1e-9;

using namespace std;

vector< pair<int, int> > dir = {
    {
        -1, 0
    },
    {
        0, 1
    },
    {
        1, 0
    },
    {
        0, -1
    }
};

bool valid(int x, int y, int n, int m) {
    return x >= 0 && y >= 0 && x < n && y < m;
}

mt19937 rng(1999999973);

const int N = 200000 + 50;
int comp[N], l[N], r[N], compR[N], compL[N], BcompR[N], BcompL[N], n, k, o = 0;
bool vis[N], vis2[N];
string s, ans;
vector<int> cur;

void doCompB(int i) {
    vis2[i] = true;
    //cur.pb(i);

    if (!vis[l[i]] && !vis2[l[i]]) {
        doCompB(l[i]);
    }
    if (!vis[r[i]] && !vis2[r[i]]) {
        doCompB(r[i]);
    }

    if (vis[l[i]])
        BcompL[o] = i;
    if (vis[r[i]])
        BcompR[o] = i;
}

void doComp(int i) {
    vis[i] = true;
    comp[i] = o;

    if (s[i] == s[l[i]] && !vis[l[i]]) {
        doComp(l[i]);
    }
    if (s[i] == s[r[i]] && !vis[r[i]]) {
        doComp(r[i]);
    }

    if (s[i] != s[l[i]])
        compL[o] = i;
    if (s[i] != s[r[i]])
        compR[o] = i;
}

unordered_map<char, char> rev;

signed main() {
    fast_io;

    rev['W'] = 'B';
    rev['B'] = 'W';

    cin >> n >> k >> s;
    ans = s;
    for (int i = 0; i < n; i++) {
        comp[i] = -1;
        l[i] = (i - 1 + n) % n;
        r[i] = (i + 1) % n;
    }

    for (int i = 0; i < n; i++) {
        if (!vis[i] && (s[i] == s[l[i]] || s[i] == s[r[i]])) {
            doComp(i);
            o++;
        }
    }

    if (o == 0) {
        for (int i = 0; i < n; i++) {
            if (k % 2 == 0)
                cout << s[i];
            else
                cout << rev[s[i]];
        }
        return 0;
    }

    o = 0;
    for (int i = 0; i < n; i++) {
        if (vis[i] || vis2[i])
            continue;
        doCompB(i);

        char leftSym = s[l[BcompL[o]]], rightSym = s[r[BcompR[o]]];

        int cur = BcompL[o];

        int col = BcompR[o] - BcompL[o];
        if (col < 0)
            col += n;
        col++;
        //cout << col << endl;

        int did = 1;
        while(true) {
            if (did <= k || col - did + 1 <= k) {
                if (did <= (col + 1) / 2)
                    ans[cur] = leftSym;
                else
                    ans[cur] = rightSym;
            }
            else {
                if (k % 2 == 1)
                    ans[cur] = rev[ans[cur]];
            }

            if (cur == BcompR[o])
                break;
            cur = r[cur];
            did++;
        }



        o++;
    }


    cout << ans;

    return 0;
}
