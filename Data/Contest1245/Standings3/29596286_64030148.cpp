#include <bits/stdc++.h>
#define all(x) begin(x), end(x)
#define dbg(x) cerr << #x << " = " << x << endl
#define _ << ' ' <<
using namespace std;
using ll = long long;
using vi = vector<int>;

ll x[2000], y[2000], c[2000], k[2000];

ll d(int i, int j)
{
    return abs(x[i] - x[j]) + abs(y[i] - y[j]);
}

struct UF
{
    vi r, p;
    UF(int n) : r(n, 0), p(n, 0)
    {
        iota(p.begin(), p.end(), 0);
    }

    int f(int x)
    {
        return (p[x] == x ? x : p[x] = f(p[x]));
    }

    void u(int i, int j)
    {
        int x = f(i), y = f(j);
        if (x == y)
            return;

        if (r[x] >= r[y])
        {
            p[y] = x;
            if (r[x] == r[y])
                r[x]++;
        }
        else
            p[x] = y;
    }

    bool s(int i, int j)
    {
        return f(i) == f(j);
    }
};

ll sol;
vi vsol;
vector<pair<int, int>> esol;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> x[i] >> y[i];

    for (int i = 0; i < n; ++i)
        cin >> c[i];
    for (int i = 0; i < n; ++i)
        cin >> k[i];

    vector<tuple<ll, int, int>> e;
    for (int i = 0; i < n; ++i)
        for (int j = i + 1; j < n; ++j)
            e.emplace_back((k[i] + k[j]) * d(i, j), i, j);

    for (int i = 0; i < n; ++i)
        e.emplace_back(c[i], i, n);

    UF uf(n + 1);
    sort(all(e));
    for (auto [c, a, b] : e)
    {
        if (!uf.s(a, b))
        {
            uf.u(a, b);
            sol += c;
            if (b == n)
                vsol.push_back(a + 1);
            else
                esol.emplace_back(a + 1, b + 1);
        }
    }
    cout << sol << '\n';
    cout << vsol.size() << '\n';
    for (int x : vsol)
        cout << x << ' ';
    cout << '\n';
    cout << esol.size() << '\n';
    for (auto [a, b] : esol)
        cout << a _ b << '\n';
}
