#include <bits/stdc++.h>
using namespace std;
int i, i0, n, m, a[100005], b[100005], c[100005], aa[100005], bb[100005], cc[100005],dic[100005],ar[100005];
vector<int> mp[100005];
bool vis[100005];
int l, r;
bool f = 1;
int sz=0;
void ddfs(int now,int root)
{
    sz++;
    for (int x : mp[now])
    {
        if (x == root)
            continue;
        ddfs(x, now);
    }
    if(mp[now].size()==1)
    {
        if(!l)l=now;
        else if(!r)r=now;
        else f=0;
    }
}
void dfs(int now, int root, int p)
{
    a[p] = aa[now];
    b[p] = bb[now];
    c[p] = cc[now];
    dic[p]=now;
    for (int x : mp[now])
    {
        if (x == root)
            continue;
        dfs(x, now, p + 1);
    }
}
int main()
{
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
        scanf("%d", &aa[i]);
    for (i = 1; i <= n; i++)
        scanf("%d", &bb[i]);
    for (i = 1; i <= n; i++)
        scanf("%d", &cc[i]);
    for (i = 1; i < n; i++)
    {
        int x, y;
        scanf("%d %d", &x, &y);
        mp[x].push_back(y);
        mp[y].push_back(x);
    }
    ddfs(1,-1);
    if (!f)
        printf("-1\n");
    else
    {
        dfs(l, -1, 1);
        long long ans = INT64_MAX, ans0;

        ans0 = 0;
        for (i = 1; i <= n; i++)
        {
            if (i % 3 == 1)
                ans0 += a[i];
            if (i % 3 == 2)
                ans0 += b[i];
            if (i % 3 == 0)
                ans0 += c[i];
        }
        ans = min(ans, ans0);

        ans0 = 0;
        for (i = 1; i <= n; i++)
        {
            if (i % 3 == 1)
                ans0 += b[i];
            if (i % 3 == 2)
                ans0 += a[i];
            if (i % 3 == 0)
                ans0 += c[i];
        }
        ans = min(ans, ans0);

        ans0 = 0;
        for (i = 1; i <= n; i++)
        {
            if (i % 3 == 1)
                ans0 += a[i];
            if (i % 3 == 2)
                ans0 += c[i];
            if (i % 3 == 0)
                ans0 += b[i];
        }
        ans = min(ans, ans0);

        ans0 = 0;
        for (i = 1; i <= n; i++)
        {
            if (i % 3 == 1)
                ans0 += c[i];
            if (i % 3 == 2)
                ans0 += a[i];
            if (i % 3 == 0)
                ans0 += b[i];
        }
        ans = min(ans, ans0);

        ans0 = 0;
        for (i = 1; i <= n; i++)
        {
            if (i % 3 == 1)
                ans0 += b[i];
            if (i % 3 == 2)
                ans0 += c[i];
            if (i % 3 == 0)
                ans0 += a[i];
        }
        ans = min(ans, ans0);

        ans0 = 0;
        for (i = 1; i <= n; i++)
        {
            if (i % 3 == 1)
                ans0 += c[i];
            if (i % 3 == 2)
                ans0 += b[i];
            if (i % 3 == 0)
                ans0 += a[i];
        }
        ans = min(ans, ans0);

        printf("%lld\n", ans);

        ans0 = 0;
        for (i = 1; i <= n; i++)
        {
            if (i % 3 == 1)
                ans0 += a[i];
            if (i % 3 == 2)
                ans0 += b[i];
            if (i % 3 == 0)
                ans0 += c[i];
        }
        if (ans == ans0)
        {
            for (i = 1; i <= n; i++)
            {
                if (i % 3 == 1)ar[dic[i]]=1;
                if (i % 3 == 2)ar[dic[i]]=2;
                if (i % 3 == 0)ar[dic[i]]=3;
            }
            for(i=1;i<=n;i++)printf("%d ",ar[i]);
            return 0;
        }

        ans0 = 0;
        for (i = 1; i <= n; i++)
        {
            if (i % 3 == 1)
                ans0 += b[i];
            if (i % 3 == 2)
                ans0 += a[i];
            if (i % 3 == 0)
                ans0 += c[i];
        }
        if (ans == ans0)
        {
            for (i = 1; i <= n; i++)
            {
                if (i % 3 == 1)ar[dic[i]]=2;
                if (i % 3 == 2)ar[dic[i]]=1;
                if (i % 3 == 0)ar[dic[i]]=3;
            }
            for(i=1;i<=n;i++)printf("%d ",ar[i]);
            return 0;
        }

        ans0 = 0;
        for (i = 1; i <= n; i++)
        {
            if (i % 3 == 1)
                ans0 += a[i];
            if (i % 3 == 2)
                ans0 += c[i];
            if (i % 3 == 0)
                ans0 += b[i];
        }
        if (ans == ans0)
        {
            for (i = 1; i <= n; i++)
            {
                if (i % 3 == 1)ar[dic[i]]=1;
                if (i % 3 == 2)ar[dic[i]]=3;
                if (i % 3 == 0)ar[dic[i]]=2;
            }
            for(i=1;i<=n;i++)printf("%d ",ar[i]);
            return 0;
        }

        ans0 = 0;
        for (i = 1; i <= n; i++)
        {
            if (i % 3 == 1)
                ans0 += c[i];
            if (i % 3 == 2)
                ans0 += a[i];
            if (i % 3 == 0)
                ans0 += b[i];
        }
        if (ans == ans0)
        {
            for (i = 1; i <= n; i++)
            {
                if (i % 3 == 1)ar[dic[i]]=3;
                if (i % 3 == 2)ar[dic[i]]=1;
                if (i % 3 == 0)ar[dic[i]]=2;
            }
            for(i=1;i<=n;i++)printf("%d ",ar[i]);
            return 0;
        }

        ans0 = 0;
        for (i = 1; i <= n; i++)
        {
            if (i % 3 == 1)
                ans0 += b[i];
            if (i % 3 == 2)
                ans0 += c[i];
            if (i % 3 == 0)
                ans0 += a[i];
        }
        if (ans == ans0)
        {
            for (i = 1; i <= n; i++)
            {
                if (i % 3 == 1)ar[dic[i]]=2;
                if (i % 3 == 2)ar[dic[i]]=3;
                if (i % 3 == 0)ar[dic[i]]=1;
            }
            for(i=1;i<=n;i++)printf("%d ",ar[i]);
            return 0;
        }

        ans0 = 0;
        for (i = 1; i <= n; i++)
        {
            if (i % 3 == 1)
                ans0 += c[i];
            if (i % 3 == 2)
                ans0 += b[i];
            if (i % 3 == 0)
                ans0 += a[i];
        }
        if (ans == ans0)
        {
            for (i = 1; i <= n; i++)
            {
                if (i % 3 == 1)ar[dic[i]]=3;
                if (i % 3 == 2)ar[dic[i]]=2;
                if (i % 3 == 0)ar[dic[i]]=1;
            }
            for(i=1;i<=n;i++)printf("%d ",ar[i]);
            return 0;
        }
    }
    return 0;
}