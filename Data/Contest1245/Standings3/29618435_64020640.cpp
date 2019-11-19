#include <bits/stdc++.h>
#define FOR(i,j,k) for(int i = j; i <= k; i ++)
#define FORD(i,j,k) for(int i = j; i >= k; i --)
#define mp make_pair
#define N 2005
//#define f first
//#define s second
//#define int long long
using namespace std;

const int MOD=1e9+7;
int n;
long long x[N], y[N];
long long res;
int par[N];
int dem1 = 0, Count = 0;
int b[N], c1[N], c2[N];
int dem = 0;
struct EDGE
{
    int u, v;
    long long w;
}canh[N * N];
long long c[N], k[N];
int get(int x)
{
    if(par[x] == 0) return x;
    else return par[x] = get(par[x]);
}
bool cmp(EDGE x123, EDGE y123)
{
    return x123.w < y123.w;
}
int main()
{
    ios_base::sync_with_stdio();
    cin.tie(0);
    cout.tie(0);
//    freopen("A.inp","r",stdin);
//    freopen("A.out","w",stdout);
    cin >> n;
    FOR(i, 1, n)
    {
        cin >> x[i] >> y[i];
    }
    FOR(i, 1, n)
    {
        cin >> c[i];
    }
    FOR(i, 1, n)
    {
        cin >> k[i];
    }
    FOR(i, 1, n)
    {
        dem ++;
        canh[dem].u = n + 1;
        canh[dem].v = i;
        canh[dem].w = c[i];
    }
    FOR(i, 1, n)
    {
        FOR(j, 1, n)
        {
            dem ++;
            canh[dem].u = i;
            canh[dem].v = j;
            canh[dem].w = (k[i] + k[j]) * (abs(x[i] - x[j]) + abs(y[i] - y[j]));
        }
    }
    sort(canh + 1, canh + dem + 1, cmp);
    FOR(i, 1, dem)
    {
        int u = get(canh[i].u);
        int v = get(canh[i].v);
        if(u != v)
        {
            par[u] = v;
            res += canh[i].w;
            if(canh[i].u == n + 1)
            {
                b[++ Count] = canh[i].v;
            }
            else
            {
                c1[++ dem1] = canh[i].u;
                c2[dem1] = canh[i].v;
            }
        }
    }
    cout << res << "\n";
    cout << Count << "\n";
    FOR(i, 1, Count) cout << b[i] << " ";
    cout << "\n";
    cout << dem1 << "\n";
    FOR(i, 1, dem1)
    {
        cout << c1[i] << " " << c2[i] << "\n";
    }
}
