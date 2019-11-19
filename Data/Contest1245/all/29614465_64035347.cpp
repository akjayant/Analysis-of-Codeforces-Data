/************************************************************************
* File Name : oj.cpp
* Purpose : 
* Creation Date : 2019年05月22日
* Last Modified : 2019年11月02日 星期六 00时29分43秒
* Created By : Elite
************************************************************************/
//#include<iostream>
//#include<string>
//#include<cmath>
//#include<vector>
//#include<set>
//#include<algorithm>
//#include<stdio.h>
//#include<stdlib.h>
//#include<queue>
//#include<stack>
//#include<string.h>


#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> P;
const int maxn = 1e6+5;
const int inf = 0x3f3f3f3f;
const ll INF = 0x3f3f3f3f3f3f3f3f;
const int mod = 1e9+7;
const double PI = acos(-1);


int n;
struct node
{
    int x, y;
}nodes[2005];

struct Edge
{
    int u, v;
    ll w;
};//e[maxn<<2];

int c[2005], k[2005];
//int mp[2005][2005];

ll getdis(int a, int b)
{
    return abs(nodes[a].x - nodes[b].x) + abs(nodes[a].y - nodes[b].y);
}
int father[2005];
void init()
{
    for(int i=1;i<=n+1;i++)
        father[i] = i;
}

//ll dis[2005], mark[2005];
vector<P> v;
int find(int x)
{
    int k = x;
    while(father[k] != k)
    {
        k = father[k];
    }
    while(father[x]!=x)
    {
        int temp = x;
        x = father[x];
        father[temp] = k;
    }
    return k;
}

void join(int a, int b)
{
    father[find(a)] = find(b);
}

vector<Edge> edges;
bool cmp(Edge a, Edge b)
{
    return a.w > b.w;
}

ll kru(int n)
{
    sort(edges.begin(), edges.end(), cmp);
    init();
    ll sum = 0;
    while(n!=1 && !edges.empty())
    {
        Edge temp = edges[edges.size()-1];
        edges.pop_back();
        if(find(temp.u) != find(temp.v))
        {
            sum += temp.w;
            v.push_back(P(temp.u, temp.v));
            n--;
            join(temp.u, temp.v);
        }
    }
    if(n!=1 && edges.empty())
        sum = -1;
    return sum;
}

int main()
{
    scanf("%d", &n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d%d", &nodes[i].x, &nodes[i].y);
    }
    for(int i=1;i<=n;i++)scanf("%d", &c[i]);
    for(int i=1;i<=n;i++)scanf("%d", &k[i]);
    for(int i=1;i<=n;i++)
    {
        for(int j=i;j<=n;j++)
        {
            Edge t;
            t.u=i, t.v=j;
            t.w = getdis(i, j) * (k[i]+k[j]);
            edges.push_back(t);
            t.u=j;t.v=i;
            edges.push_back(t);
        }
    }
    for(int i=1;i<=n;i++)
    {
        Edge t;
        t.u=i;t.v=n+1;
        t.w = c[i];
        edges.push_back(t);
        t.u=n+1;t.v=i;
        edges.push_back(t);
    }
    ll ans = kru(n+1);
    printf("%lld\n", ans);
    vector<int> tmp;
    for(auto x : v)
    {
        if(x.first==n+1)
        {
            tmp.push_back(x.second);
        }
        if(x.second==n+1)
        {
            tmp.push_back(x.first);
        }
    }
    printf("%d\n", (int)tmp.size());
    for(auto x : tmp)
        printf("%d ", x);
    printf("\n");
    printf("%d\n", (int)(v.size()-tmp.size()));
    for(auto x : v)
    {
        if(x.first!=n+1 && x.second!=n+1)
        {
            printf("%d %d\n", x.first, x.second);
        }
    }
    printf("\n");
    return 0;
}
