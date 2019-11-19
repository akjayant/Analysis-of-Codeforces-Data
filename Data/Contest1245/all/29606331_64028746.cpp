#include <iostream>
#include <cmath>
#include <utility>
#include <algorithm>
#include <vector>

const int MAX = 2001;
int n;
int64_t G[MAX][MAX];
bool GG[MAX][MAX];
int64_t X[MAX];
int64_t Y[MAX];
int64_t C[MAX];
int64_t K[MAX];
std::pair<int, int> E[MAX*MAX];

int T[MAX];
int L[MAX];

int find(int x)
{
    if (T[x] == x) return x;
    else return T[x] = find(T[x]);
}

void join(int x, int y)
{
    if (L[x] < L[y])
    {
        T[x] = y;
        ++L[y];
    }
    else
    {
        T[y] = x;
        ++L[x];
    }
}

int64_t dist(int a, int b)
{
    return (abs(X[a]-X[b]) + abs(Y[a]-Y[b])) * (K[a]+K[b]);
}

bool cmp(const std::pair<int64_t, int64_t>& l, const std::pair<int64_t, int64_t>& r)
{
    return G[l.first][l.second] < G[r.first][r.second];
}

int main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin >> n;
    for (int i=1;i<=n;++i)
        std::cin >> X[i] >> Y[i];
    for (int i=1;i<=n;++i)
        std::cin >> C[i];
    for (int i=1;i<=n;++i)
        std::cin >> K[i];
    for (int i=1;i<=n;++i)
        for (int j=i+1;j<=n;++j)
            G[i][j] = dist(i, j);
    for (int i=1;i<=n;++i)
        G[0][i] = C[i];
    int ii=0;
    for (int i=0;i<=n;++i)
        for (int j=i+1;j<=n;++j)
            E[ii++] = std::make_pair(i, j);
    std::sort(E, E+ii, cmp);
    int64_t cost = 0;
    std::vector<int> plants;
    std::vector<std::pair<int,int>> wires;
    for (int i=0;i<=n;++i) T[i] = i;
    for (int i=0;i<ii;++i)
    {
        auto& p = E[i];
        if (find(p.first) == find(p.second)) continue;
        cost += G[p.first][p.second];
        join(find(p.first), find(p.second));
        if (p.first == 0) plants.push_back(p.second);
        else wires.push_back(p);
    }
    std::cout << cost << "\n";
    std::cout << plants.size() << "\n";
    for (int p : plants) std::cout << p << " ";
    std::cout << "\n";
    std::cout << wires.size() << "\n";
    for (const auto& w : wires) std::cout << w.first << " " << w.second << "\n";
    return 0;
}