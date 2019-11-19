#include<bits/stdc++.h>
#define int long long


using namespace std;
vector<vector<int> >adj;
int c[3][100005];
int ans[100005];
int temp[100005];
int res=0;
void dfs(int ver,int x,int p)
{
    res+=c[x%3][ver];
    temp[ver]=x%3;
    for(auto i:adj[ver])
    {
        if(i!=p)
        {
            dfs(i,x+1,ver);
        }
    }
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    adj.resize(n+1);
    for (int i = 0; i <3 ; ++i) {
        for (int j = 0; j < n; ++j) {
            cin>>c[i][j];
        }
    }
    
    int x,y;
    int mm[n+1]={0};
    for (int i = 0; i < n-1; ++i) {
        cin>>x>>y;
        x--;
        y--;
        mm[x]++;
        mm[y]++;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    int cnt1=0,cnt2=0;
    int ind;
    for (int i = 0; i < n; ++i) {
        if(mm[i]==1)
        {
            ind=i;
            cnt1++;
        }
        else if(mm[i]==2)
            cnt2++;
    }

    if(cnt1+cnt2!=n)
    {
        cout<<-1;
        return 0;
    }
    if(cnt1!=2)
    {
        cout<<-1;
        return 0;
    }

    int mn=1e17;
    dfs(ind,0,-1);
    if(mn>res)
    {
        mn=res;
        for (int i = 0; i < n; ++i) {
            ans[i]=temp[i]+1;
        }
    }

    res=0;
    dfs(ind,1,-1);
    if(mn>res)
    {
        mn=res;
        for (int i = 0; i < n; ++i) {
            ans[i]=temp[i]+1;
        }
    }
    res=0;
    dfs(ind,2,-1);
    if(mn>res)
    {
        mn=res;
        for (int i = 0; i < n; ++i) {
            ans[i]=temp[i]+1;
        }
    }
    for (int i = 0; i < n; ++i) {
        swap(c[0][i],c[1][i]);
    }
    res=0;
    dfs(ind,0,-1);
    if(mn>res)
    {
        mn=res;
        for (int i = 0; i < n; ++i) {
            if(temp[i]==0)
                ans[i]=2;
            else if(temp[i]==1)
                ans[i]=1;
            else
                ans[i]=3;
        }
    }
    res=0;
    dfs(ind,1,-1);
    if(mn>res)
    {
        mn=res;
        for (int i = 0; i < n; ++i) {
            if(temp[i]==0)
                ans[i]=2;
            else if(temp[i]==1)
                ans[i]=1;
            else
                ans[i]=3;
        }
    }
    res=0;
    dfs(ind,2,-1);
    if(mn>res)
    {
        mn=res;
        for (int i = 0; i < n; ++i) {
            if(temp[i]==0)
                ans[i]=2;
            else if(temp[i]==1)
                ans[i]=1;
            else
                ans[i]=3;
        }
    }

    cout<<mn<<"\n";
    for (int i = 0; i < n; ++i) {
        cout<<ans[i]<<" ";
    }
}