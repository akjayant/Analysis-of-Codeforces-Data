#include <bits/stdc++.h>
#define all(x) begin(x), end(x)
#define dbg(x) cerr << #x << " = " << x << endl
#define _ << ' ' <<
using namespace std;
using ll = long long;
using vi = vector<int>;

const int N = 100001;
int c[3][N];
vi adj[N];
vi top;
vi col;

void dfs(int x, int p)
{
    top.push_back(x);
    for (int y : adj[x])
        if (y != p)
            dfs(y, x);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> c[0][i];
    for (int i = 0; i < n; ++i)
        cin >> c[1][i];
    for (int i = 0; i < n; ++i)
        cin >> c[2][i];

    for (int i = 1; i < n; ++i)
    {
        int a, b;
        cin >> a >> b;
        a--; b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    int root = -1;
    for (int i = 0; i < n; ++i)
    {
        if (adj[i].size() > 2)
            return cout << -1, 0;
        if (adj[i].size() == 1)
            root = i;
    }
    assert(root != -1);
    dfs(root, -1);
    assert(top.size() == n);
    int a[3] = {0, 1, 2};
    ll sol = 1e18; int b[3];
    do
    {
        ll cost = 0;
        for (int i = 0; i < 3; ++i)
            cost += c[a[i]][top[i]];
        int p = a[1], q = a[2];
        for (int i = 3; i < n; ++i)
        {
            int r = 0 ^ 1 ^ 2 ^ p ^ q;
            cost += c[r][top[i]];
            p = q;
            q = r;
        }
        if (cost < sol)
        {
            sol = cost;
            memcpy(b, a, sizeof a);
        }
    } while (next_permutation(a, a + 3));
    cout << sol << '\n';
    col.resize(n);
    for (int i = 0; i < 3; ++i)
        col[top[i]] = b[i] + 1;
    int p = b[1], q = b[2];
    for (int i = 3; i < n; ++i)
    {
        int r = 0 ^ 1 ^ 2 ^ p ^ q;
        col[top[i]] = r + 1;
        p = q;
        q = r;
    }
    for (int i = 0; i < n; ++i)
        cout << col[i] << ' ';
}
