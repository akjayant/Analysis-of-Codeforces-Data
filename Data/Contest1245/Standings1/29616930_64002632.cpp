/**Lucky Boy**/
#include <bits/stdc++.h>
#define FOR(i, a, b) for (int i = (a); i <= (b); ++i)
#define FORD(i, a, b) for (int i = (a); i >= (b); --i)
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define maxc 1000000007
#define maxn 2003
#define maxm 1000006
#define pii pair <int,int>
#define Task ""
template <typename T> inline void read(T &x){char c;bool nega=0;while((!isdigit(c=getchar()))&&(c!='-'));if(c=='-'){nega=1;c=getchar();}x=c-48;while(isdigit(c=getchar())) x=x*10+c-48;if(nega) x=-x;}
template <typename T> inline void writep(T x){if(x>9) writep(x/10);putchar(x%10+48);}
template <typename T> inline void write(T x){if(x<0){putchar('-');x=-x;}writep(x);putchar(' ');}
template <typename T> inline void writeln(T x){write(x);putchar('\n');}
using namespace std;
int n,k[maxn],root[maxn];
pii a[maxn];
long long ans;
vector <int> save1;
vector <pii> save2;
vector <pair <long long,pii> > ed;
int Dis(pii x,pii y)
{
    return abs(x.F - y.F) + abs(x.S - y.S);
}
int Get_root(int x)
{
    return root[x] ? root[x] = Get_root(root[x]) : x;
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie();
    //freopen(Task".inp", "r",stdin);
    //freopen(Task".out", "w",stdout);
    cin >> n;
    FOR(i,1,n)
    {
        cin >> a[i].F >> a[i].S;
    }
    FOR(i,1,n)
    {
        int x;cin >> x;
        ed.pb(mp(x,mp(i,n+1)));
    }
    FOR(i,1,n) cin >> k[i];
    FOR(i,1,n)
        FOR(j,i+1,n)
        {
            long long dis = 1ll*(k[i] + k[j]) * Dis(a[i],a[j]);
            ed.pb(mp(dis,mp(i,j)));
        }
    sort(ed.begin(),ed.end());
    for (auto id : ed)
    {
        long long w = id.F;
        int u = id.S.F,
            v = id.S.S;
        u = Get_root(u),
        v = Get_root(v);
        if (u == v) continue;
        if (id.S.S == n + 1)
        {
            save1.pb(id.S.F);
        }
        else
        {
            save2.pb(id.S);
        }
        ans += w;
        root[u] = v;
    }
    cout << ans << '\n';
    cout << save1.size() << '\n';
    for (auto v : save1) cout << v << ' ';
    if (save1.size()) cout << '\n';
    cout << save2.size() << '\n';
    for (auto v : save2)
        cout << v.F << ' ' << v.S << '\n';
    return 0;
}
