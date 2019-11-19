#include <bits/stdc++.h>
#define FOR(i, j, k) for (auto i = j; i <= k; i++)
#define FORD(i, j, k) for (auto i = j; i >= k; i--)
#define maxC 1000000007
#define mn 100005

using namespace std;
int n, m, k;
set<pair<int, int>> obs;
vector<int> inX[mn], inY[mn];

void setup()
{
    cin >> n >> m >> k;
    int x, y;
    FOR(i, 1, k)
    {
        cin >> x >> y;
        obs.insert(make_pair(x, y));
        inX[x].push_back(y);
        inY[y].push_back(x);
    }
}

bool check(int start)
{
    int minX = 1, maxX = n;
    int minY = 1, maxY = m;
    int x = 1, y = 1, newX = 1, newY = 1;
    long long remain = 1ll * n * m - k - 1;
    bool turned = false;

    for (int dir = start;; dir = (dir == 4 ? 1 : dir + 1))
    {
        if (turned)
        {
            if (x == newX && y == newY)
                return false;
        }
        turned = true;
        remain -= abs(newX - x) + abs(newY - y);
        if (!remain)
            break;
        x = newX, y = newY;

        if (dir == 1)
        {
            auto it = upper_bound(inX[x].begin(), inX[x].end(), y);
            if (it == inX[x].end())
            {
                newY = maxY;
                minX++;
                continue;
            }
            int toY = (*it);
            if (toY > maxY)
            {
                newY = maxY;
                minX++;
                continue;
            }
            FOR(_x, minX, maxX)
            FOR(_y, toY, maxY)
            if (!obs.count(make_pair(_x, _y)))
                return false;
            newY = maxY = toY - 1;
            minX++;
        }
        if (dir == 2)
        {
            auto it = upper_bound(inY[y].begin(), inY[y].end(), x);
            if (it == inY[y].end())
            {
                newX = maxX;
                maxY--;
                continue;
            }
            int toX = (*it);
            if (toX > maxX)
            {
                newX = maxX;
                maxY--;
                continue;
            }
            FOR(_x, toX, maxX)
            FOR(_y, minY, maxY)
            if (!obs.count(make_pair(_x, _y)))
                return false;
            newX = maxX = toX - 1;
            maxY--;
        }
        if (dir == 3)
        {
            auto it = lower_bound(inX[x].begin(), inX[x].end(), y);
            if (it == inX[x].begin())
            {
                newY = minY;
                maxX--;
                continue;
            }
            int toY = (*(--it));
            if (toY < minY)
            {
                newY = minY;
                maxX--;
                continue;
            }
            FOR(_x, minX, maxX)
            FOR(_y, minY, toY)
            if (!obs.count(make_pair(_x, _y)))
                return false;
            newY = minY = toY + 1;
            maxX--;
        }
        if (dir == 4)
        {
            auto it = lower_bound(inY[y].begin(), inY[y].end(), x);
            if (it == inY[y].begin())
            {
                newX = minX;
                minY++;
                continue;
            }
            int toX = (*(--it));
            if (toX < minX)
            {
                newX = minX;
                minY++;
                continue;
            }
            FOR(_x, minX, toX)
            FOR(_y, minY, maxY)
            if (!obs.count(make_pair(_x, _y)))
                return false;
            newX = minX = toX + 1;
            minY++;
        }
    }
    return true;
}

void xuly()
{
    FOR(i, 1, n)
    sort(inX[i].begin(), inX[i].end());
    FOR(i, 1, m)
    sort(inY[i].begin(), inY[i].end());
    if (check(1))
        cout << "Yes";
    else if (check(2))
        cout << "Yes";
    else 
        cout << "No";
}

main()
{
    iostream::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    setup();
    xuly();
    return 0;
}