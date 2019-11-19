#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>

using namespace std;

#define N 100008

int n, m, k, sn = 1, sm = 1;
int heada = 1, taila, headb = 1, tailb;
int nxt[5] = {0, 2, 3, 4, 1};

struct node {
    int x, y;
}a[N], b[N];

bool cmp1(const node &t1, const node &t2)
{
    if (t1.x == t2.x)
        return t1.y < t2.y;
    return t1.x < t2.x;
}

bool cmp2(const node &t1, const node &t2)
{
    if (t1.y == t2.y)
        return t1.x > t2.x;
    return t1.y < t2.y;
}

bool checkcol1(int st, int last)
{
    int cnt;
    for (int i = last; i >= st; i--)
    {
        cnt = 0;
        while (b[tailb].y == i)
        {
            if (b[tailb].x >= sn && b[tailb].x <= n)
                ++cnt;
            tailb--;
        }
        if (cnt != n-sn+1)
            return false;
    }
    return true;
}

bool checkrow2(int st, int last)
{
    int cnt;
    for (int i = last; i >= st; i--)
    {
        cnt = 0;
        while (a[taila].x == i)
        {
            if (a[taila].y >= sm && a[taila].y <= m)
                ++cnt;
            taila--;
        }
        if (cnt != m-sm+1)
            return false;
    }
    return true;
}

bool checkcol3(int st, int last)
{
    int cnt;
    for (int i = st; i <= last; i++)
    {
        cnt = 0;
        while (b[headb].y == i)
        {
            if (b[headb].x >= sn && b[headb].x <= n)
                ++cnt;
            headb++;
        }
        if (cnt != n-sn+1)
            return false;
    }
    return true;
}

bool checkrow4(int st, int last)
{
    int cnt;
    for (int i = st; i <= last; i++)
    {
        cnt = 0;
        while (a[heada].x == i)
        {
            if (a[heada].y >= sm && a[heada].y <= m)
                ++cnt;
            heada++;
        }
        if (cnt != m-sm+1)
            return false;
    }
    return true;
}

bool solve()
{
    int x = 1, y = 1, to = 1;
    while(sn <= n && sm <= m)
    {
        switch(to)
        {
            case 1:
                while (a[heada].x == x && a[heada].y < y)
                    heada++;
                if (a[heada].x == x)
                {
                    if (a[heada].y <= m)
                    {
                        if (!checkcol1(a[heada].y, m))
                            return false;
                        m = a[heada].y-1;
                    }
                    while (a[heada].x == x && heada <= k)
                        heada++;
                }
                sn++;
                y = m;
                break;
            case 2:
                while (b[tailb].y == y && b[tailb]. x < x)
                    tailb--;
                if (b[tailb].y == y)
                {
                    if (b[tailb].x <= n)
                    {
                        if (!checkrow2(b[tailb].x, n))
                            return false;
                        n = b[tailb].x-1;
                    }
                    while (b[tailb].y == y && tailb >= 1)
                        tailb--;
                }
                m--;
                x = n;
                break;
            case 3:
                while (a[taila].x == x && a[taila].y > y)
                    taila--;
                if (a[taila].x == x)
                {
                    if (a[taila].y >= sm)
                    {
                        if (!checkcol3(sm, a[taila].y))
                            return false;
                        sm = a[taila].y+1;
                    }
                    while (a[taila].x == x && taila >= 1)
                        taila--;
                }
                n--;
                y = sm;
                break;
            case 4:
                while (b[headb].y == y && b[headb].x > x)
                    headb++;
                if (b[headb].y == y)
                {
                    if (b[headb].x >= sn)
                    {
                        if (!checkrow4(sn, b[headb].x))
                            return false;
                        sn = b[headb].x+1;
                    }
                    while (b[headb].y == y && headb <= k)
                        headb++;
                }
                sm++;
                x = sn;
                break;
        }
        to = nxt[to];
    }
    return true;
}

int main()
{
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 1; i <= k; i++)
    {
        scanf("%d%d", &a[i].x, &a[i].y);
        b[i].x = a[i].x;
        b[i].y = a[i].y;
    }
    taila = tailb = k;
    sort(a+1, a+1+k, cmp1);
    sort(b+1, b+1+k, cmp2);
    if (!solve())   printf("No\n");
    else printf("Yes\n");
    return 0;
}