#include <bits/stdc++.h>

#define taskname ""
#define pb push_back
#define eb emplace_back
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define for0(i, n) for (int i = 0; i < (int)(n); ++i)
#define for1(i, n) for (int i = 1; i <= (int)(n); ++i)
#define ford(i, n) for (int i = (int)(n) - 1; i >= 0; --i)
#define fore(i, a, b) for (int i = (int)(a); i <= (int)(b); ++i)

using namespace std;

typedef long long ll;
typedef long double ld;
typedef complex <ld> cd;
typedef vector <cd> vcd;
typedef vector <int> vi;

template<class T> using v2d = vector <vector <T> >;
template<class T> bool uin(T &a, T b)
{
    return a > b ? (a = b, true) : false;
}
template<class T> bool uax(T &a, T b)
{
    return a < b ? (a = b, true) : false;
}

mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

const int maxN = 2e3 + 1;

int n;
struct city
{
    ll x, y, k, c;
    ll dist(city a)
    {
        return (k + a.k) * (abs(x - a.x) + abs(y - a.y));
    }
} ct[maxN];

int parent[maxN];
int id[maxN];
ll cost[maxN];
ll sta[maxN];

int FindSet(int u)
{
    if (u == parent[u])
    {
        return u;
    }
    return parent[u] = FindSet(parent[u]);
}

ll res = 0;

vector <pair<int, int> > vp;
vector <pair<int, int> > r;

int cnt = 0, c = 0;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for1(i, n)
    {
        cin >> ct[i].x >> ct[i].y;
    }
    for1(i, n)
    {
        cin >> ct[i].c;
        sta[i] = cost[i] = ct[i].c;
        parent[i] = id[i] = i;
    }
    for1(i, n)
    {
        cin >> ct[i].k;
    }
    for1(i, n)
    {
        for1(j, i - 1)
        {
            vp.eb(i, j);
        }
    }
    sort(all(vp), [](pair<int, int> a, pair<int, int> b)
         {
             return ct[a.fi].dist(ct[a.se]) < ct[b.fi].dist(ct[b.se]);
         });
    for (auto &p: vp)
    {
        int u = p.fi, v = p.se;
        int uk = FindSet(u), vk = FindSet(v);
        if (uk != vk)
        {
            if (cost[uk] + cost[vk] - max(sta[uk], sta[vk]) + ct[u].dist(ct[v]) <= cost[uk] + cost[vk])
            {
                ++cnt;
                parent[vk] = uk;
                cost[uk] += cost[vk] - max(sta[uk], sta[vk]) + ct[u].dist(ct[v]);
                cost[vk] = 0;
                if (sta[uk] > sta[vk])
                {
                    sta[uk] = sta[vk];
                    id[uk] = id[vk];
                }
                sta[vk] = 0;
                id[vk] = 0;
                r.eb(u, v);
            }
        }
    }
    for1(i, n)
    {
        res += cost[i];
        c += (id[i] != 0);
    }
    cout << res << '\n' << c << '\n';
    for1(i, n)
    {
        if (id[i])
        {
            cout << id[i] << ' ';
        }
    }
    cout << '\n' << cnt << '\n';
    for (auto &p: r)
    {
        cout << p.fi << ' ' << p.se << '\n';
    }
    return 0;
}
