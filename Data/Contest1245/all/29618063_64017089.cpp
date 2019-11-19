//#include <bits/stdc++.h>

#include <iostream>//数据输入输出流
#include <string.h>//字符串操作函数
#include <stdio.h>//C的输入输出
#include <stdlib.h>//定义杂项函数及内存分配函数
#include <math.h>//C中的数学函数
#include <string.h>//c++中的string类 他不能用strcpy等c函数去操作
#include <vector>//STL vetor容器
#include <list>//STL list
#include <map>// STL map
#include <queue>// STL queue
#include <stack>//sTL stack
#include <bitset>//bitset可按位定义串
#include <algorithm>//STL各种算法 比如 swap sort merge max min 比较
#include <numeric>//常用数字操作 一般和algorithm搭配使用
#include <functional>//STL定义运算函数（代替运算符）



using namespace std;

typedef long long LL;
typedef long long ULL;
typedef pair<int, int> pr;
typedef pair<LL, LL> lpr;
typedef pair<double, double> dpr;
typedef pair<long double, long double> ldpr;
//typedef complex<double> cp;

const int next_x[8] = {0, 1, -1, 0, 1, 1, -1, -1};
const int next_y[8] = {1, 0, 0, -1, 1, -1, -1, 1};
const int inf = 2147483647;
const LL linf = 1e18 + 5;
const double PI = acos(-1.0);

// #define DEBUG 1  //调试开关
struct IO
{
#define MAXSIZE (1 << 20)
#define isdigit(x) (x >= '0' && x <= '9')
    char buf[MAXSIZE], *p1, *p2;
    char pbuf[MAXSIZE], *pp;
#if DEBUG
#else
    IO() : p1(buf), p2(buf), pp(pbuf)
    {
    }
    ~IO() { fwrite(pbuf, 1, pp - pbuf, stdout); }
#endif
    inline char gc()
    {
#if DEBUG //调试，可显示字符
        return getchar();
#endif
        if (p1 == p2)
            p2 = (p1 = buf) + fread(buf, 1, MAXSIZE, stdin);
        return p1 == p2 ? -1 : *p1++;
    }
    inline bool blank(char ch)
    {
        return ch == ' ' || ch == '\n' || ch == '\r' || ch == '\t';
    }
    template <class T>
    inline void read(T &x)
    {
        register double tmp = 1;
        register bool sign = 0;
        x = 0;
        register char ch = gc();
        for (; !isdigit(ch); ch = gc())
            if (ch == '-')
                sign = 1;
        for (; isdigit(ch); ch = gc())
            x = x * 10 + (ch - '0');
        if (ch == '.')
            for (ch = gc(); isdigit(ch); ch = gc())
                tmp /= 10.0, x += tmp * (ch - '0');
        if (sign)
            x = -x;
    }
    inline void read(char *s)
    {
        register char ch = gc();
        for (; blank(ch); ch = gc())
            ;
        for (; !blank(ch); ch = gc())
            *s++ = ch;
        *s = 0;
    }
    inline void read(char &c)
    {
        for (c = gc(); blank(c); c = gc())
            ;
    }
    inline void push(const char &c)
    {
#if DEBUG //调试，可显示字符
        putchar(c);
#else
        if (pp - pbuf == MAXSIZE)
            fwrite(pbuf, 1, MAXSIZE, stdout), pp = pbuf;
        *pp++ = c;
#endif
    }
    template <class T>
    inline void write(T x)
    {
        if (x < 0)
            x = -x, push('-'); // 负数输出
        static T sta[35];
        T top = 0;
        do
        {
            sta[top++] = x % 10, x /= 10;
        } while (x);
        while (top)
            push(sta[--top] + '0');
    }
    template <class T>
    inline void write(T x, char lastChar)
    {
        write(x), push(lastChar);
    }
} io;

#define dbgs(x) #x << " = " << x
#define dbgs2(x, y) dbgs(x) << ", " << dbgs(y)
#define dbgs3(x, y, z) dbgs2(x, y) << ", " << dbgs(z)
#define dbgs4(w, x, y, z) dbgs3(w, x, y) << ", " << dbgs(z)

#define heap priority_queue
#define mst(s, x) memset(s, x, sizeof(s))
//#define mid ((l + r) >> 1)
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
#define gow(u) for (rg int i = pre[u], v = e[i].v, w = e[i].w; i; i = e[i].next, v = e[i].v, w = e[i].w)
#define dbga(a, len)                       \
    {                                      \
        cout << #a << ": ";                \
        fp(i, 1, len) cout << a[i] << " "; \
        cout << endl;                      \
    }
#define ub upper_bound
#define lb lower_bound

const double eps = 1e-10;
const int MAXN = 2010*2010 + 5;
//const int N = 200 + 5;
const LL MAX = 1e10;

/*----------head----------*/

int n,m;
struct edge
{
    int u,v;
    LL w;
    bool operator <(const edge &t)const
    {
        return w<t.w;
    }
}e[MAXN];

int f[MAXN];
int find(int x){return f[x]==x?x:f[x]=find(f[x]);}
void merge(int a,int b)
{
    int fa=find(a),fb=find(b);
    if(fa==fb) return;
    f[fa]=fb;
}
int x[MAXN],y[MAXN],k[MAXN],c[MAXN];
LL dis(int i,int j)
{
    return abs(x[i]-x[j])+abs(y[i]-y[j]);
}

int work()
{
    scanf("%d",&n);
    fp(i,1,n)scanf("%d%d",&x[i],&y[i]);
    fp(i,1,n)scanf("%d",&c[i]);
    fp(i,1,n)scanf("%d",&k[i]);
    fp(i,1,n)fp(j,1,n)if(i!=j)e[++m]={i,j,dis(i,j)*(k[i]+k[j])};
    fp(i,1,n)e[++m]={i,n+1,c[i]};
    fp(i,1,n+1)f[i]=i;
    sort(e+1,e+1+m);
    vector<int> P;
    vector<pr> E;
    LL ans=0;
    fp(i,1,m)
    {
        if(find(e[i].u)!=find(e[i].v))
        {
            if(e[i].u==n+1) P.pb(e[i].v);
            else if(e[i].v==n+1) P.pb(e[i].u);
            else E.pb({e[i].u,e[i].v});
            merge(e[i].u,e[i].v),ans+=e[i].w;
        }
    }
    printf("%lld\n",ans);
    printf("%d\n",P.size());
    for(auto x:P) printf("%d ",x);printf("\n");
    printf("%d\n",E.size());
    for(auto e:E) printf("%d %d\n",e.fi,e.se);
    return 0;
}

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