#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ULL;
typedef long long LL;
typedef pair<int, int> pr;
typedef pair<LL, LL> lpr;
typedef pair<double, double> dpr;
typedef pair<long double, long double> ldpr;
//typedef complex<double> cp;

const int next_x[8] = {0, 1, -1, 0, 1, 1, -1, -1};
const int next_y[8] = {1, 0, 0, -1, 1, -1, -1, 1};
const int inf = 214748364;//7;
const LL linf = 1e18 + 5;
const double PI = acos(-1.0);

#define dbgs(x) #x << " = " << x
#define dbgs2(x, y) dbgs(x) << ", " << dbgs(y)
#define dbgs3(x, y, z) dbgs2(x, y) << ", " << dbgs(z)
#define dbgs4(w, x, y, z) dbgs3(w, x, y) << ", " << dbgs(z)

#define heap priority_queue
#define mst(s, x) memset(s, x, sizeof(s))
#define mid ((l + r) >> 1)
#define fi first
#define se second
#define pb push_back
#define pf push_front
#define ppb pop_back
#define ppf pop_front
#define mp make_pair
#define all(x) x.begin(), x.end()
#define unq(x) x.erase(unique(x.begin(), x.end()), x.end())
#define rg register
#define fp(i, a, b) for (rg int i = (a), I = (b) + 1; i < I; ++i)
#define fd(i, a, b) for (rg int i = (a), I = (b)-1; i > I; --i)
#define go(u) for (rg int i = pre[u], v = e[i].v; i; i = e[i].next, v = e[i].v)
#define gow(u) for (rg LL i = pre[u], v = e[i].v, w = e[i].w; i; i = e[i].next, v = e[i].v, w = e[i].w)
#define dbga(a, len)                       \
    {                                      \
        cout << #a << ": ";                \
        fp(i, 1, len) cout << a[i] << " "; \
        cout << endl;                      \
    }
#define ub upper_bound
#define lb lower_bound
#define bitcount __builtin_popcount

const double eps = 1e-10;
const int MAXN = 1e5+5;
const int N = 10;
const int fix = 1e5;

/*----------head----------*/

LL n;
vector<LL> ans;
int work()
{
    //fp(i,1,100)
    {
        scanf("%lld",&n);
        //cout << dbgs(n) << " ";
        ans.clear();
        //scanf("%lld",&n);
        for(LL i=2;i*i<=n;i++)
        {
            int cnt=0;
            while(n%i==0)n/=i,cnt++;
            if(cnt)ans.pb(i);
        }
        if(n!=1)ans.pb(n);
        if(ans.size()==1)printf("%lld\n",ans.front());
        else printf("1\n");

    }
}

/*
int n;
int f[MAXN];
int find(int x)
{   
    return f[x]==x?x:f[x]=find(f[x]);
}
void merge(int a,int b)
{
    int fa=find(a),fb=find(b);
    if(fa==fb) return;
    f[fa]=fb;
}
void init()
{
    fp(i,1,n)f[i]=i;
}
int work()
{
    for(n=1;n<=100;n++)
    {
        init();
        fp(i,1,n)fp(j,1,i-2)
            if(n%(i-j)==0)
                merge(i,j);
        int ans=0;
        fp(i,1,n)if(find(i)==i)ans++;
        cout << dbgs2(n,ans) << endl;
    }
}
*/
// vector+lower_bound常数 < map/set
// map.find不会创建新元素 map[]会 注意空间
// 别对指针用memset
// 用位运算表示2^n注意加LL  1LL<<20
// 注意递归爆栈
// 注意边界
// 注意memset 多组样例会T

//#define ONLINE_JUDGE

int main()
{
    //ios::sync_with_stdio(false);
    //cin.tie(0);
#ifdef ONLINE_JUDGE
    //freopen("invazia.in", "r",stdin );
    //freopen("invazia.out","w",stdout);
#endif // ONLINE_JUDGE
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif
    work();
#ifndef ONLINE_JUDGE
    freopen("CON", "r", stdin);
    fflush(stdout);
    system("pause");
#endif
    return 0;
}

