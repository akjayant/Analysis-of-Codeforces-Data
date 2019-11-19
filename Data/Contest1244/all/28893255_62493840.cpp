#include<bits/stdc++.h>
#include<vector>
#include<string.h>
using namespace std;
#define MAX 100001
#define MAX_POINTS 201
#define DEFAULT 1;
#define FASTIO          ios_base::sync_with_stdio(false);cin.tie(NULL)
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")
vector<int>Graph[MAX];
long long int c[3][MAX];
vector<int> Arr;
int colour[MAX];
void dfs(int node,int from)
{
    Arr.push_back(node);
    int i;
    for(i=0;i<Graph[node].size();i++)
    {
        if(Graph[node][i]==from) continue;
        dfs(Graph[node][i],node);
    }
}
int main ()
{
    int n,i,j;
    scanf("%d",&n);
    for(i=0;i<3;i++)
    {
        for(j=1;j<=n;j++)
        {
            scanf("%I64d",&c[i][j]);
        }
    }
    for(i=0;i<n-1;i++)
    {
        int u,v;
        scanf("%d %d",&u,&v);
        Graph[u].push_back(v);
        Graph[v].push_back(u);
    }
    int root=-1;
    for(i=1;i<=n;i++)
    {
        if(Graph[i].size()==1) root=i;
        if(Graph[i].size()>2)
        {
            printf("-1");
            return 0;
        }
    }
    dfs(root,root);
    int combinations[6][3]={0,1,2,0,2,1,1,0,2,1,2,0,2,0,1,2,1,0};
    long long int mcost=1000000000000000000;
    int com=-1;
    for(i=0;i<6;i++)
    {
        long long int curr=0;
        for(j=0;j<n;j++)
        {
            curr=curr+c[combinations[i][j%3]][Arr[j]];
        }
        if(curr<mcost)
        {
            mcost=curr;
            com=i;
        }
    }
    for(i=0;i<n;i++)
    {
        colour[Arr[i]]=combinations[com][i%3];
    }
    printf("%I64d\n",mcost);
    for(i=1;i<=n;i++)
    {
        printf("%d ",colour[i]+1);
    }
    return 0;
}
