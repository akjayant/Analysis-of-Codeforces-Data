#include<iostream>
#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define IO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
int n, a[5][100009], col[100009];
vector<int> v[100009];
ll inf=2e14;
ll dp[100009][4][4];
ll solve(int i, int last1, int last2, int p)
{
    ll &ans=dp[i][last1][last2];
    if(ans!=-1)
        return ans ;
    ll op;
    ans=inf;
    op=inf;
    for(int j=1; j<=3; j++)
        if(j!=last1&& j!=last2)
        {
            op=a[j][i];
            for(auto node : v[i])
                if(node!=p)
                    op+=solve(node,last2,j,i);
            ans=min(ans,op);
        }
    return ans ;
}
void build(int i, int last1, int last2, int p)
{
    ll op, ans;
    ans=op=inf;
    int id=0;
    bool good=1;
    for(int j=1; j<=3; j++)
        if(j!=last1&& j!=last2)
        {
            op=a[j][i];
            for(auto node : v[i])
                if(node!=p)
                    op+=solve(node,last2,j,i);
            if(op<ans)
                ans=op, id=j;
        }
    col[i]=id;
    for(auto node : v[i])
        if(node!=p)
            build(node,last2,id,i);
}
int main()
{
    IO
    cin>>n;
    memset(dp, -1, sizeof dp);
    for(int j=1; j<=3; j++)
        for(int i=1; i<=n; i++)
            cin>>a[j][i];
    for(int i=1; i<n; i++)
    {
        int  x, y ;
        cin>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    for(int i=1; i<=n; i++)
        if(v[i].size()>2)
            return cout<<-1, 0 ;
    int node ;
    for(int i=1; i<=n; i++)
        if(v[i].size()==1)
        {
            node=i;
            break;
        }
    cout<<solve(node,0,0,0)<<endl;
    build(node,0,0,0);
    for(int i=1; i<=n; i++)
        cout<<col[i]<<" ";
}
