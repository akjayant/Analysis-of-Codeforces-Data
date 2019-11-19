#include <bits/stdc++.h>

using namespace std;

#define int long long 
#define N 100005


vector < int > a[N];
int cost[N][3];
int deg[N];
int vis[N];
int dp[N][3][3];
vector < int > arr;
int golu[N];

void dfs(int n)
{
    vis[n] = 1;
    arr.push_back(n);
    for(int i=0;i<a[n].size();i++)
    {
        if(vis[a[n][i]] == 0)
            dfs(a[n][i]);
    }
}

int find(int j, int k)
{
    int left;
    if( (j==0 && k==1) || (j==1 && k==0) )
        left = 2;                
    if( (j==1 && k==2) || (j==2 && k==1) )
        left = 0;
    if( (j==0 && k==2) || (j==2 && k==0) )
        left = 1;
    return left;
}


int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;

    for(int i=1;i<=n;i++)  
        cin>>cost[i][0];
    
    for(int i=1;i<=n;i++)
        cin>>cost[i][1];
    
    for(int i=1;i<=n;i++)
        cin>>cost[i][2];

    for(int i=0;i<n-1;i++)
    {
        int u, v;
        cin>>u>>v;
        deg[u]++;
        deg[v]++;

        a[u].push_back(v);
        a[v].push_back(u);
        if(deg[u] > 2 || deg[v] > 2)
        {
            cout<<-1<<endl;
            return 0;
        }
    }

    arr.push_back(0);
    for(int i=1;i<=n;i++)
    {
        if(deg[i]==1)
        {
            dfs(i);
            break;
        }
    }

    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<3;j++)
        {
            for(int k=0;k<3;k++)
            {
                dp[i][j][k] = 1e15;
            }
        }
    }

    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            if(i==j)
                continue;
            dp[1][i][j] = min(dp[1][i][j], cost[arr[1]][i]); 
        }
    }


    for(int i=2;i<=n;i++)
    {
        for(int j=0;j<3;j++)
        {
            for(int k=0;k<3;k++)
            {
                if(j==k)
                    continue;
                
                int left = find(j, k);
                dp[i][j][k] = min(dp[i][j][k], dp[i-1][k][left] + cost[arr[i]][j]);
            }
        }
    }

    int ans = 1e15;
    int last = 0;
    int secondl = 0; 
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            if(ans > dp[n][i][j])
            {
                last = i;
                secondl = j;
            }
            ans = min(ans, dp[n][i][j]);

        }
    }
    cout<<ans<<endl;
    
    golu[arr[n]] = last;
    golu[arr[n-1]] = secondl;

    for(int i=n-2;i>=1;i--)
    {
        int temp = find(golu[arr[i+1]], golu[arr[i+2]]);
        golu[arr[i]] = temp;

    }

    for(int i=1;i<=n;i++)
        cout<<golu[i]+1<<" ";
    cout<<endl;
    return 0;
}
