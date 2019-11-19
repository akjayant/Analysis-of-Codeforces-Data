#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define f first
#define s second

vector<int> adj[100005];
ll n , x , y , no , leaf , st , clr[5][100005] , mn=1e18 , cur;
ll arr[3] = {1,2,3} , arr2[3] , ans[100005];
bool visited[100005];

void dfs(int node , ll val)
{
    visited[node]=1;
    cur += clr[arr[val%3]][node];

    for(int i=0; i<adj[node].size(); i++)
    {
        int ch = adj[node][i];
        if (!visited[ch]) dfs(ch , val+1);
    }
}

void printt(int node , ll val)
{
    visited[node]=1;
    ans[node] = arr2[val%3];
    for(int i=0; i<adj[node].size(); i++)
    {
        int ch = adj[node][i];
        if (!visited[ch]) printt(ch , val+1);
    }
}

int main()
{
    scanf("%lld",&n);

    for(int i=1; i<=n; i++)
        scanf("%lld",&clr[1][i]);

    for(int i=1; i<=n; i++)
        scanf("%lld",&clr[2][i]);

    for(int i=1; i<=n; i++)
        scanf("%lld",&clr[3][i]);

    for(int i=1; i<n; i++)
    {
        scanf("%lld%lld",&x,&y);
        adj[x].push_back(y);
        adj[y].push_back(x);
        if (adj[x].size() > 2 || adj[y].size() > 2) no=1;
    }

    for(int i=1; i<=n; i++)
    {
        if (adj[i].size()==1) {leaf++; st=i;}
    }
    if (leaf != 2) no=1;


    do
    {
        cur=0;
        memset(visited , 0 , sizeof visited);
        dfs(st , 0);
        if (mn > cur)
        {
            mn = cur;
            for(int i=0; i<3; i++)
                arr2[i]=arr[i];

        }
    }while(next_permutation(arr , arr+3));



    if (no) printf("-1\n");
    else
    {
        printf("%lld\n",mn);
        memset(visited , 0 , sizeof visited);
        printt(st,0);
        for(int i=1; i<=n; i++)
            printf("%lld ",ans[i]);
    }

    return 0;
}
