#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

struct Edge
{
    int x, y;
    long long val;

    Edge(int x = 0, int y = 0, long long val = 0)
        :x(x), y(y), val(val)   {}

    const bool operator <(const Edge &tmp) const{
        return this->val < tmp.val;
    }
}edge[2010 * 2010];
int cntE = 0;

int x[2010], y[2010];
long long k[2010], c[2010];
int fa[2010];

queue<int> base;
queue<int> line[2];

long long dist(int i, int j)
{
    return (long long)abs(x[i] - x[j]) + (long long)abs(y[i] - y[j]);
}

int find(int x)
{
    return fa[x] == x? x: fa[x] = find(fa[x]);
}

int main()
{
    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    for (int i = 0; i<=n; i++)
        fa[i] = i;

    for (int i = 1; i<=n; i++)
        cin >> x[i] >> y[i];

    for (int i = 1; i<=n; i++)
    {
        cin >> c[i];

        edge[cntE ++] = Edge(0, i, c[i]);
    }
    
    for (int i = 1; i<=n; i++)
        cin >> k[i];

    for (int i = 1; i<=n; i++)
        for (int j = i + 1; j<=n; j++)
            edge[cntE ++] = Edge(i, j, dist(i,j) * (k[i] + k[j]));
    
    sort(edge, edge + cntE);

    long long ans = 0;
    for (int i = 0; i<cntE; i++)
    {
        int f_a = find(edge[i].x), f_b = find(edge[i].y);

        if (f_a != f_b)
        {
            if (edge[i].x == 0)
                base.push(edge[i].y);
            else
            {
                line[0].push(edge[i].x);
                line[1].push(edge[i].y);
            }

            ans += edge[i].val;
            fa[f_b] = f_a;
        }
    }

    cout << ans << endl;
    cout << base.size() << endl;
    while (!base.empty())
    {
        cout << base.front() << " ";
        base.pop();
    }
    cout << endl;

    cout << line[0].size() << endl;
    while (!line[0].empty())
    {
        cout << line[0].front() << " " << line[1].front() << endl;
        line[0].pop();
        line[1].pop();
    }
}