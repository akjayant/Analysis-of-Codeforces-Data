#include <bits/stdc++.h>
using namespace std;
int n,m;
vector<int> v[100005];
int vis[100005];
int a[100005];

int find_father(int x)
{
    if (a[x]==x) return x;
    else return a[x]=find_father(a[x]);
}

void Union(int x,int y)
{
    a[find_father(x)]=find_father(y);
}

int main()
{
    scanf("%d%d",&n,&m);
    for (int i=1;i<=n;i++)
    {
        a[i]=i;
    }
    for (int i=1;i<=m;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        v[x].push_back(y);
        v[y].push_back(x);
    }
    int mi=-1,p=-1;
    for (int i=1;i<=n;i++)
    {
        if (v[i].size()<mi)
        {
            mi=v[i].size();
            p=i;
        }
    }
    for (auto x:v[p])
    {
        vis[x]=1;
    }
    set<int> s;
    for (int i=1;i<=n;i++)
    {
        if (vis[i]==0) a[i]=p;
        else s.insert(i);
    }
    for (int i=1;i<=n;i++)
    {
        if (vis[i]==1)
        {
            set<int> ss=s;
            int cnt=v[i].size();
            for (auto x:v[i])
            {
                if (ss.find(x)!=ss.end()) ss.erase(x);
            }
            if (cnt-(s.size()-ss.size())!=n-s.size() && find_father(i)!=find_father(p)) Union(i,p);
            for (auto x:ss)
            {
                if (x!=i &&find_father(i)!=find_father(x)) Union(i,x);
            }
        }
    }
    int ans=0;
    for (int i=1;i<=n;i++)
    {
        for (auto x:v[i])
        {
            if (find_father(x)!=find_father(i))
            {
                ans++;
                Union(i,x);
            }
        }
    }
    printf("%d\n",ans);
    return 0;
}
