#include<bits/stdc++.h>
int f[2222];
inline int find(int x)
{
  if(f[x] != x)
    f[x] = find(f[x]);
  return f[x];
}
struct Point
{
    int x, y;
}p[2222];

int64_t c[2222];
int64_t k[2222];
struct Edge
{
    int64_t w;
    int from, to;
}e[4444444];
bool cmp(const Edge &e1, const Edge &e2)
{
    return e1.w < e2.w;
}

std::pair<int, int> fangAng[22222];
int chongdian[22222];

int main()
{
    int n;
    std::cin >> n;
    int eCnt = 0;
    for (int i = 0; i < n; ++i)
    {
        f[i] = i;
        std::cin >> p[i].x >> p[i].y;
    }
    f[n] = n;
    f[n + 1] = n + 1;
    for (int i = 0; i < n; ++i)
    {
        std::cin >> c[i];
        e[eCnt].w = c[i];
        e[eCnt].from = 1;
        e[eCnt].to = i + 2;
        ++eCnt;
    }
    for (int i = 0; i < n; ++i)
    {
        std::cin >> k[i];
        for (int j = 0; j < i; ++j)
        {
            e[eCnt].w = (k[i] + k[j]) * (abs(p[i].x - p[j].x) + abs(p[i].y - p[j].y));
            e[eCnt].from = j + 2;
            e[eCnt].to = i + 2;
            eCnt++;
        }
    }
    std::sort(e, e + eCnt, cmp);
    int fangAngCnt = 0;
    int chongDianCnt = 0;
    int64_t ans = 0;

    for (int i = 0; i < eCnt; ++i)
    {
        if (fangAngCnt + chongDianCnt == n)
            break;
        int x = e[i].from;
        int y = e[i].to;
        int dx = find(x);
        int dy = find(y);
        if (dx != dy)
        {
            f[dx] = dy;
            ans += e[i].w;
            if (x == 1)
            {
                chongdian[chongDianCnt++] = y - 1;
            }
            else
            {
                fangAng[fangAngCnt].first = x - 1;
                fangAng[fangAngCnt++].second = y - 1;
            }

        }
    }
    std::cout << ans << std::endl;
    std::cout << chongDianCnt << std::endl;
    for (int i = 0; i < chongDianCnt; ++i)
    {
        std::cout << chongdian[i];
        if (i == chongDianCnt - 1)std::cout << std::endl;
        else std::cout << " ";
    }
    std::cout << fangAngCnt << std::endl;
    for (int i = 0; i < fangAngCnt; ++i)
    {
        std::cout << fangAng[i].first << " " << fangAng[i].second << std::endl;
    }

}

