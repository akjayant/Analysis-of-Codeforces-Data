#include <bits/stdc++.h>
#define getbit(x, i) (x >> (i - 1) & 1)
#define onbit(x, i) (x | (1 << (i - 1)))
#define offbit(x, i) (x ^ (1 << (i - 1)))
#define cntone(x) (__builtin_popcount(x))
#define sum(x, y, u, v) (f[u][v] - f[x - 1][v] - f[u][y - 1] + f[x - 1][y - 1])

using namespace std;

typedef long long ll;
typedef pair < int, int > pii;
const int oo = 1e9;
const int maxn = 1e6 + 10;

int n, m, res, cnt[maxn], f[maxn], Min = oo, r;
set < int > a[maxn];
multiset < int > ss;
priority_queue < pii, vector < pii >, greater < pii > > q;
vector < int > vec;

ll Rand(ll l, ll h)
{
    return l + ((ll)rand() * (RAND_MAX + 1) * (RAND_MAX + 1) * (RAND_MAX + 1) +
                (ll)rand() * (RAND_MAX + 1) * (RAND_MAX + 1) +
                (ll)rand() * (RAND_MAX + 1) +
                rand()) % (h - l + 1);
}

template < typename T > inline void read(T &x)
{
    x = 0; char c;
    while(!isdigit(c = getchar()));
    do x = x * 10 + c - 48; while(isdigit(c = getchar()));
}

template < typename T > void Write(T x)
{
    if(x > 9)
        Write(x / 10);
    putchar(x % 10 + 48);
}

void dij()
{
    q.push(make_pair(0, r));
    for(int i = 1; i <= n; i++) f[i] = oo;
    f[r] = 0;
    while(q.size())
    {
        int u = q.top().second, cost = q.top().first;
        q.pop();
        if(cost != f[u]) continue;
        res +=
        f[u]; f[u] = 0;
        vec.clear();
        for(auto p : ss)
            if(a[u].find(p) == a[u].end() &&
               f[p] > 0)
        {
            f[p] = 0;
            q.push(make_pair(f[p], p));
            vec.push_back(p);
        }
        for(auto p : vec)
            if(ss.find(p) != ss.end())
                ss.erase(ss.find(p));
        for(auto v : a[u])
            if(f[v] > 1)
        {
            f[v] = 1;
            q.push(make_pair(f[v], v));
        }
    }
    cout << res;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    if(fopen("1.inp", "r"))
    {
       freopen("1.inp", "r", stdin);
       freopen("1.out", "w", stdout);
    }
    cin >> n >> m;
    for(int u, v, i = 1; i <= m; i++)
    {
        cin >> u >> v;
        a[u].insert(v);
        a[v].insert(u);
        cnt[u]++; cnt[v]++;
    }
    for(int i = 1; i <= n; i++)
        if(Min > cnt[i])
    {
        Min = cnt[i];
        r = i;
    }
    for(int i = 1; i <= n; i++)
        if(i != r) ss.insert(i);
    dij();

}
