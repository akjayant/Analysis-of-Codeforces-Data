#include <bits/stdc++.h>

using namespace std;

#define mem(a,b) memset(a,b,sizeof(a))
#define FOR(i,j,k) for(int i=j;i<=k;i++)
#define read        freopen("in.txt", "r", stdin)
#define write       freopen("out.txt", "w", stdout)
#define pf          printf
#define sf(n)       scanf("%d", &n)
#define sff(a,b)    scanf("%d %d", &a, &b)
#define PB push_back
#define F first
#define S second
#define MP make_pair

typedef pair<int,int> pii;
typedef long long LL;

const int MAX = (1e5) + 5;

int ara[5][MAX], node[MAX], ord;
vector<int> mat[MAX];

void dfs(int p,int pa)
{
    node[ord++] = p;
    for(int x : mat[p])
    {
        if(x == pa) continue;
        dfs(x, p);
    }
}

LL dp[MAX][5][5];

LL rec(int p,int pa,int paa)
{
    //cout << p << ' ' << pa << ' ' << paa << endl;
    if(p == ord) return 0;

    LL &temp = dp[p][pa][paa];
    if(temp != -1) return temp;

    temp = (1e16);
    FOR(i,1,3)
    {
        if(i == paa || i == pa) continue;
        temp = min(temp, rec(p + 1, i, pa) + ara[i][ node[p] ]);
    }
    return temp;
}

int show[MAX];
void prin(int p,int pa,int paa)
{
   // cout << p << ' ' << pa << ' ' << paa << endl;
    if(p == ord) return;

    LL temp = rec(p, pa, paa);

    FOR(i,1,3)
    {
        if(i == paa || i == pa) continue;
       /// cout << temp << ' ' << rec(p + 1, i, pa) + ara[i][ node[p] ] << ' ' << endl;
        if(temp == rec(p + 1, i, pa) + ara[i][ node[p] ])
        {
            show[ node[p] ] = i;
            prin(p + 1, i, pa);
            return;
        }
    }
    return;
}

void solve()
{
    int n, u, v;

    cin >> n;
    FOR(i,1,3) FOR(j,1,n) cin >> ara[i][j];

    FOR(i,1,n-1)
    {
        cin >> u >> v;
        mat[u].PB(v); mat[v].PB(u);
    }

    int st = -1;
    FOR(i,1,n)
    {
        if(mat[i].size() > 2)
        {
            cout << -1 << endl;
            return;
        }
        if(mat[i].size() == 1) st = i;
    }
    dfs(st, 0);
    mem(dp, -1);
    cout << rec(0, 0, 0) << endl;
    prin(0, 0, 0);

//    FOR(i,0,ord-1) cout << node[i] << ' ';
//    cout << endl;
    FOR(i,1,n) cout << show[i] << ' ';
}

int main()
{
    ios::sync_with_stdio(false);
    //read;
    solve();
    return 0;
}

