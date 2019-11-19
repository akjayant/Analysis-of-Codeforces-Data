#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>

using namespace std;


typedef long long ll;

const ll INF = 1e18;
const int N = 2002;


int x[N], y[N];
int k[N];

ll g[N][N];
bool used[N];
int mn[N];

int main()
{
    //freopen("input.txt", "r", stdin);


    int n;
    scanf("%d", &n);
    n += 1;
    for (int i = 1; i < n; ++i)
        scanf("%d %d", x + i, y + i);
    for (int i = 1; i < n; ++i)
    {
        scanf("%lld", g[0] + i);
        g[i][0] = g[0][i];
    }
    for (int i = 1; i < n; ++i)
        scanf("%d", k + i);
    for (int i = 1; i < n; ++i)
        for (int j = 1; j < n; ++j)
            g[i][j] = (k[i] + k[j]) * 1LL * (abs(x[i] - x[j]) + abs(y[i] - y[j]));


    for (int v = 0; v < n; ++v)
        mn[v] = 0;

    used[0] = true;
    ll ans = 0;
    vector< pair<int,int > > out;
    for (int it = 1; it < n; ++it)
    {
        int bestV = -1;
        ll bestW = INF;
        for (int v = 0; v < n; ++v)
        {
            if (used[v]) continue;
            if (v == -1 || g[v][mn[v]] < bestW)
            {
                bestV = v;
                bestW = g[v][mn[v]];
            }
        }
        used[bestV] = true;
        ans += bestW;
        out.push_back({bestV, mn[bestV]});
        for (int v = 0; v < n; ++v)
        {
            if (used[v]) continue;
            if (g[v][mn[v]] > g[v][bestV])
                mn[v] = bestV;
        }
    }

    vector<int> out2;
    for (int i = 0; i < (int)out.size(); ++i)
    {
        if (out[i].first == 0)
        {
            out2.push_back(out[i].second);
            swap(out[i], out.back());
            out.pop_back();
            --i;
        }
        else if (out[i].second == 0)
        {
            out2.push_back(out[i].first);
            swap(out[i], out.back());
            out.pop_back();
            --i;
        }
    }

    printf("%lld\n", ans);
    printf("%d\n", (int)out2.size());
    for (int x : out2)
        printf("%d ", x);
    printf("\n");
    printf("%d\n", (int)out.size());
    for (auto pr : out)
        printf("%d %d\n", pr.first, pr.second);

}
