#include <bits/stdc++.h>
/*
#pragma GCC optimize ("O3")
#pragma GCC target ("avx2")
#pragma GCC target (sse, sse2, sse3, ssse3, sse4,popcnt,tune=native)
*/
#define FOR(i, s, e) for(int i=s; i<e; i++)
#define loop(i, n) for(int i=0; i<n; i++)
#define CIN   ios_base::sync_with_stdio(0); cin.tie(0)
#define pb push_back
#define ll long long int
#define ull unsigned long long int
#define ld long double
#define SZ(a) (int)(a.size())
#define Read() freopen("input.txt", "r", stdin)
#define Write() freopen("output.txt", "w", stdout)
#define mem(a, v) memset(a, v, sizeof(a))
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define Unique(x)  x.erase(unique(all(x)), x.end())
#define pi acos(-1.0)
#define vec vector
#define mp make_pair
#define paii pair<int, int>
#define padd pair<dd, dd>
#define pall pair<ll, ll>
#define fr first
#define sc second
//#define endl "\n"
#define vec vector

using namespace std;

#define int long long

const int MAXN = 3e5 + 47, inf = 1e9 + 47;

string st;
int n, p, w, d;

vec<vec<int> > a(MAXN, vec<int>(3, 0));
vec<vec<int> > graf(MAXN);

void read() {
    cin >> n;
    loop(i, n) cin >> a[i][0];
    loop(i, n) cin >> a[i][1];
    loop(i, n) cin >> a[i][2];

    loop(i, n - 1) {
        int p1, p2;
        cin >> p1 >> p2;
        --p1, --p2;
        graf[p1].pb(p2);
        graf[p2].pb(p1);
    }
}

vec<vec<int> > dp(MAXN, vec<int>(6, 0));

void dfs(int p1, int pr) {
    for(int p2 : graf[p1]) {
        if(p2 == pr) continue;
        dfs(p2, p1);

        dp[p1][0] = dp[p2][3] + a[p1][0];
        dp[p1][1] = dp[p2][5] + a[p1][0];
        dp[p1][2] = dp[p2][1] + a[p1][1];
        dp[p1][3] = dp[p2][4] + a[p1][1];
        dp[p1][4] = dp[p2][0] + a[p1][2];
        dp[p1][5] = dp[p2][2] + a[p1][2];
        return;
    }

    dp[p1][0] = dp[p1][1] = a[p1][0];
    dp[p1][2] = dp[p1][3] = a[p1][1];
    dp[p1][4] = dp[p1][5] = a[p1][2];
}

vec<int> cock(3, 0);
vec<int> loh(MAXN, -1);

void get(int p1, int pr, int h) {
    loh[p1] = cock[h % 3];
    for(int p2 : graf[p1]) {
        if(p2 == pr) continue;
        get(p2, p1, h + 1);
    }
}

void solve() {
    loop(i, n) {
        if(SZ(graf[i]) > 2) {
            cout << -1 << endl;
            return;
        }
    }

    loop(i, n) {
        if(SZ(graf[i]) == 1) {
            dfs(i, -1);
            int as = dp[i][0], ind = 0;
            loop(l, 6) if(as > dp[i][l]) as = dp[i][l], ind = l;
            if(ind == 0) cock = {1, 2, 3};
            if(ind == 1) cock = {1, 3, 2};
            if(ind == 2) cock = {2, 1, 3};
            if(ind == 3) cock = {2, 3, 1};
            if(ind == 4) cock = {3, 1, 2};
            if(ind == 5) cock = {3, 2, 1};
            cout << as << endl;
            get(i, -1, 0);
            loop(p, n) cout << loh[p] << " " ;
            cout << endl;
            return;
        }
    }
}

signed main()
{
    CIN;
    int t = 1;
    //cin >> t;
    while(t--) {
        read();
        solve();
    }
}
/*

3
3 2 3
4 3 2
3 1 3
1 2
2 3

5
3 4 2 1 2
4 2 1 5 4
5 3 2 1 1
1 2
3 2
4 3
5 3

5
3 4 2 1 2
4 2 1 5 4
5 3 2 1 1
1 2
3 2
4 3
5 4
*/
