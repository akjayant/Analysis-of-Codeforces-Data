#pragma GCC optimize("Ofast,fast-math,unroll-loops")
  
#include <bits/stdc++.h>
  
#define int ll
//#define double long double
#define endl '\n'
#define all(C) (C).begin(), (C).end()
#define rall(C) (C).rbegin(), (C).rend()
#define mp make_pair 
#define pb emplace_back
#define dbg(x) cerr << #x << " : " << x << endl
#define PI 3.14159265358979
  
using namespace std;
        
using ll = long long;
using ull = unsigned long long;
using ld = long double;
using pii = pair <int, int>;
        
/* 
const ll MAX_MEM = 7e8;
char MEM[MAX_MEM];
ll MEM_POS = 0;
void* operator new(size_t x)
{
    auto ret = MEM + MEM_POS;
    MEM_POS += x;
    assert(MEM_POS < MAX_MEM);
    return ret;
}
void operator delete(void*)
{}
*/
        
template <class T>
istream& operator>> (istream &in, vector <T> &a)
{
    for (auto &i : a)
        in >> i;
    return in;
}
        
template <class T> 
ostream& operator<< (ostream &out, vector <T> a)
{
    for (auto &i : a)
        out << i << ' ';
    return out;
}
        
template <class T, class U>
istream& operator>> (istream &in, pair <T, U> &p)
{
    in >> p.first >> p.second;
    return in;
}
        
template <class T, class U>
ostream& operator<< (ostream &out, pair <T, U> p)
{
    out << p.first << " " << p.second << " ";
    return out;
}
        
inline void Start()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    //freopen(".in", "r", stdin);
    //freopen(".out", "w", stdout);
}

struct DSU
{
    vector <int> p;
    int n;
    DSU() {}
    DSU(int _n)
    {
        n = _n;
        p.resize(n, -1);
    }
    int get(int v)
    {
        return p[v] < 0 ? v : p[v] = get(p[v]);
    }
    void unit(int u, int v)
    {
        u = get(u);
        v = get(v);
        if (u == v)
            return;
        if (-p[u] < -p[v])
            swap(u, v);
        p[u] += p[v];
        p[v] = u;
    }
};

#define x first
#define y second
ll dist(pii a, pii b)
{
    return llabs(a.x - b.x) + llabs(a.y - b.y);
}

signed main()
{
    Start();
    int n;
    cin >> n;
    vector <pii> a(n);
    cin >> a;
    vector <int> c(n), k(n);
    cin >> c >> k;
    vector <pair <int, pii>> e;
    for (int i = 0; i < n; ++i)
    {
        e.pb(c[i], mp(0, i + 1));
    }
    for (int i = 0; i < n; ++i)
    {
        for (int j = i + 1; j < n; ++j)
        {
            e.pb((k[i] + k[j]) * dist(a[i], a[j]), mp(i + 1, j + 1));
        }
    }
    sort(all(e));
    DSU pel(n + 1);
    int ans = 0;
    vector <int> ver;
    vector <pii> edg;
    for (auto &[w, uv] : e)
    {
        int u = uv.x, v = uv.y;
        if (pel.get(u) == pel.get(v))
            continue;
        ans += w;
        pel.unit(u, v);
        if (u == 0)
        {
            ver.pb(v);
        }
        else
            edg.pb(uv);
    }
    cout << ans << endl << ver.size() << endl << ver << endl << edg.size() << endl;
    for (auto &i : edg)
        cout << i << endl;
    return 0;
}
