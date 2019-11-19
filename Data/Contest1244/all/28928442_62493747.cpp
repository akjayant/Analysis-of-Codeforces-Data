// Need to git gud and reach 1900+
#include <bits/stdc++.h>
using namespace std;

#define ok puts("ok")
#define ll long long
#define pb push_back
#define mk make_pair
#define fr first
#define sc second
#define vi vector < int >
#define pi pair < int, int >

const int N = 1e6 + 7;
const ll INF = 1e18 + 7;

ll a[3][N], dp[3][3][3], h[N], clr[N];
int n, t, ans1, ans2;

vi g[N];

ll rec (int v, int c1, int c2, int p){
    ll res = 0;
    h[v] = h[p] + 1;
    for (int to : g[v])
        if (to != p)
            res += rec(to, c1, c2, v);
    if (h[v] % 3 == 0){
        for (int i = 0; i < 3; i++){
            if (i != c1 && i != c2){
                clr[v] = i;
                return res + a[i][v];
            }
        }
    }
    else if (h[v] % 3 == 1){
        clr[v] = c1;
        return res + a[c1][v];
    }
    else {
        clr[v] = c2;
        return res + a[c2][v];
    }

}

ll dfs (int v = 1){
    ll res = INF;
    h[v] = 0;
    if (g[v].size() == 2){
        t = 2;
        for (int i = 0; i < 3; i++){
            for (int j = 0; j < 3; j++){
                for (int c = 0; c < 3; c++){
                    if (i == j || i == c || j == c)
                        continue;
                    dp[0][j][c] = rec(g[v][0], j, c, v);
                }
            }
        }
        for (int i = 0; i < 3; i++){
            for (int j = 0; j < 3; j++){
                for (int c = 0; c < 3; c++){
                    if (i == j || i == c || j == c)
                        continue;
                    dp[1][j][c] = rec(g[v][1], j, c, v);
                }
            }
        }
        for (int i = 0; i < 3; i++){
            for (int j = 0; j < 3; j++){
                for (int c = 0; c < 3; c++){
                    if (i == j || i == c || j == c)
                        continue;
                    ll gg = dp[0][j][c] + dp[1][c][j] + a[i][v];
                    if (res > gg){
                        res = gg;
                        ans1 = j;
                        ans2 = c;
                    }
                }
            }
        }
    }
    else if (g[v].size() == 1) {
        t = 1;
        for (int i = 0; i < 3; i++){
            for (int j = 0; j < 3; j++){
                for (int c = 0; c < 3; c++){
                    if (i == j || i == c || j == c)
                        continue;
                    ll gg = rec(g[v][0], j, c, v) + a[i][v];
                    if (res > gg){
                        res = gg;
                        ans1 = j;
                        ans2 = c;
                    }
                }
            }
        }
    }
    else {
        res = -1;
    }
    return res;
}

main(){ // If you don't know what to do, check the text box at the bottom
    cin >> n;
    bool ex = false;
    for (int i = 0; i < 3; i++)
        for (int j = 1; j <= n; j++)
            scanf("%lld", &a[i][j]);
    for (int i = 1; i < n; i++){
        int a, b;
        scanf("%d%d", &a, &b);
        g[a].pb(b);
        g[b].pb(a);
        if (g[a].size() > 2 || g[b].size() > 2){
            ex = true;
        }
    }
    if (ex == true){
        puts("-1");
        return 0;
    }
    ll res = dfs();
    if (res == -1){
        puts("-1");
        return 0;
    }
    cout << res << endl;
    if (t == 1){
        rec(g[1][0], ans1, ans2, 1);
    }
    else {
        rec(g[1][0], ans1, ans2, 1);
        rec(g[1][1], ans2, ans1, 1);
    }
    for (int i = 0; i < 3; i++)
        if (ans1 != i && ans2 != i)
            clr[1] = i;
    for (int i = 1; i <= n; i++)
        printf("%lld ", clr[i] + 1);
}

/*
    Totally not inspired by BenQ's template
    Things you should do:
    1. Look for stupid typos in code e.g 1 instead of -1 etc
    2. Check if there is no infinite loops
    3. "Measure twice, cut once"
    4. Stay focused
*/
