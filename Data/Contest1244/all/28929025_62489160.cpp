/*
  AUTHOR:SOURABH
  CREATED:12:10:19
*/
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define ordered_set tree<pair<int, int> , null_type, less< pair<int, int> >, rb_tree_tag, tree_order_statistics_node_update>
#define ll long long int
#define ld long double
#define fi first
#define se second
#define pb push_back
#define pob pop_back
#define W while
#define fn(i,x) for(i=0;i<x;i++)
#define fs(i,s,x) for(i=s;i<x;i++)
#define fr(i,x) for(i=x;i>=0;i--)
#define fit(it,s) for(it=s.begin();it!=s.end();it++)
#define mp make_pair
#define pii pair<int,int>
#define pll pair<ll,ll>
#define vii vector<int>
#define vll vector<ll>
#define mii map<int,int>
#define mll map<ll,ll>
#define mod 1000000007
#define MAX 100005
#define M 32

using namespace std;
using namespace __gnu_pbds;

vector<vll> adj(100001);
vll ans(6);
ll a[100001][3],b[100001],sum,v[6][100001];

void dfs1(ll root,ll prev,ll id)
{
    ll i,j,k;
    k=adj[root].size();
    v[id][root]=b[root]+1;
    sum+=a[root][b[root]];
    fn(i,k)
    {
        j=adj[root][i];
        if(j!=prev)
        {
            if(b[root]==0)
                b[j]=1;
            else if(b[root]==1)
                b[j]=2;
            else
                b[j]=0;
            dfs1(j,root,id);
        }
    }
}
void dfs2(ll root,ll prev,ll id)
{
    ll i,j,k;
    v[id][root]=b[root]+1;
    sum+=a[root][b[root]];
    k=adj[root].size();
    fn(i,k)
    {
        j=adj[root][i];
        if(j!=prev)
        {
            if(b[root]==0)
                b[j]=2;
            else if(b[root]==1)
                b[j]=0;
            else
                b[j]=1;
            dfs2(j,root,id);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

    ll n,i,j,u,w,s,id,mi=1e15;
    cin>>n;
    fn(i,3)
    {
        fs(j,1,n+1)
        cin>>a[j][i];
    }
    fn(i,n-1)
    {
        cin>>u>>w;
        adj[u].pb(w);
        adj[w].pb(u);
    }
    fs(i,1,n+1)
    {
        if(adj[i].size()>2)
        {cout<<-1;return 0;}
        else if(adj[i].size()==1)
            s=i;
    }

    b[s]=0;
    sum=0;
    dfs1(s,0,0);
    ans[0]=sum;
    sum=0;
    dfs2(s,0,1);
    ans[1]=sum;


    b[s]=1;
    sum=0;
    dfs1(s,0,2);
    ans[2]=sum;
    sum=0;
    dfs2(s,0,3);
    ans[3]=sum;

    b[s]=2;
    sum=0;
    dfs1(s,0,4);
    ans[4]=sum;
    sum=0;
    dfs2(s,0,5);
    ans[5]=sum;

    fn(i,6)
    {
        if(ans[i]<mi)
        {
            mi=ans[i];
            id=i;
        }
    }
    cout<<mi<<"\n";
    fs(i,1,n+1)
    cout<<v[id][i]<<" ";
    return 0;
}








