#include <iostream>
#include <vector>
#include <algorithm>

long long int cost[100010][3];
std::vector< std::vector< int> > g(100010);
int permut[4];
int colors[100010];

long long int solve(int index, int cnt)
{
    long long int cur = 0;
    long long int parent = -1;

    while (1)
    {
        cur += cost[index][permut[cnt]];
        cnt = (cnt + 1) % 3;
        bool flag = false;
        for (int i = 0; i < g[index].size(); ++i)
        {
            int nxt = g[index][i];
            if (nxt != parent)
            {
                flag = true;
                parent = index;
                index = nxt;
                break;
            }
        }

        if (!flag)
            return cur;
    }
}

void solveFill(int index, int cnt)
{
    long long int parent = -1;

    while (1)
    {
        colors[index] = permut[cnt];
        cnt = (cnt + 1) % 3;
        bool flag = false;
        for (int i = 0; i < g[index].size(); ++i)
        {
            int nxt = g[index][i];
            if (nxt != parent)
            {
                flag = true;
                parent = index;
                index = nxt;
                break;
            }
        }

        if (!flag)
            return;
    }
}

int main()
{
    int n;
    std::cin >> n;

    for (int i = 0; i < n; ++i)
        std::cin >> cost[i][0];
    for (int i = 0; i < n; ++i)
        std::cin >> cost[i][1];
    for (int i = 0; i < n; ++i)
        std::cin >> cost[i][2];

    int x, y;
    bool flag = true;
    for (int i = 1; i < n; ++i)
    {
        std::cin >> x >> y;
        --x;
        --y;
        g[x].push_back(y);
        g[y].push_back(x);
        if (g[x].size() > 2 || g[y].size() > 2)
            flag = false;
    }

    if (!flag)
    {
        std::cout << "-1";
        return 0;
    }
    int start = -1;
    for (int i = 0; i < n; ++i)
    {
        if (g[i].size() == 1)
            start = i;
    }

    for (int i = 0; i < 3; ++i)
        permut[i] = i;

    long long int ans = -1, anstime = -1;
    for (int i = 0; i < 10; ++i)
    {
        long long int cur = solve(start, 0);
        if (ans == -1)
        {
            ans = cur;
            solveFill(start, 0);
        }
        else if (cur < ans)
        {
            ans = cur;
            solveFill(start, 0);
        }

        std::next_permutation(permut, permut + 3);
    }

    std::cout << ans << "\n";
    for (int i = 0; i < n; ++i)
        std::cout << colors[i] + 1 << " ";
}
