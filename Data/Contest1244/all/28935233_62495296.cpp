#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<ll,ll>
#define pic pair<ll,char>
#define pci pair<char,ll>
#define pll pair<ll,ll>
#define plc pair<ll,char>
#define pcl pair<char,ll>
#define vi vector<ll>
#define vl vector<ll>
#define vii vector<pii>
#define vll vector<pll>
#define vic vector<pic>
#define vci vector<pci>
#define vlc vector<plc>
#define vcl vector<pcl>
#define pb push_back
#define endl '\n'
const ll MOD=1e9+7;
const ll INF=1e9;
const ll MAXN=3e5+6;
const ll MAXM=1e5+6;
vector<ll>g[MAXN];
ll n;
ll c[4][MAXN];
ll depth[MAXN];
ll col[MAXN];
void dfs(ll u,ll par)
{
    depth[u]=depth[par]+1;
    for(ll i=0;i<g[u].size();i++)
    {
        if(g[u][i]==par)continue;
        dfs(g[u][i],u);
        break;
    }
}
vector<int>v[3];
int main()
{
    /*ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);*/
    cin>>n;
    for(ll i=1;i<=3;i++)
    for(ll j=1;j<=n;j++)
    {
        cin>>c[i][j];
    }
    for(ll i=1;i<n;i++)
    {
        ll x,y;
        cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    ll root=-1;
    for(ll i=1;i<=n;i++)
    {
        if(g[i].size()>=3)
        {
            cout<<"-1\n";
            return 0;
        }
        if(g[i].size()==1)root=i;
    }
    //cout<<"1\n";
    dfs(root,0);
    //cout<<"2\n";
    for(int i=1;i<=n;i++)
    {
        v[depth[i]%3].push_back(i);
    }
    vector<int> p={1,2,3};
    vector<int> ansp;
    ll ans=1e17;
    do
    {
        ll s=0;
        for(int i=0;i<v[0].size();i++)
        {
            s+=c[p[0]][v[0][i]];
        }
        for(int i=0;i<v[1].size();i++)
        {
            s+=c[p[1]][v[1][i]];
        }
        for(int i=0;i<v[2].size();i++)
        {
            s+=c[p[2]][v[2][i]];
        }
        if(s<ans)
        {
            ans=s;
            ansp=p;
        }
        //cout<<"*\n";
    }while(next_permutation(p.begin(),p.end()));
    //cout<<"3\n";
    for(int i=0;i<v[0].size();i++)
    {
        col[v[0][i]]=ansp[0];
    }
    for(int i=0;i<v[1].size();i++)
    {
        col[v[1][i]]=ansp[1];
    }
    for(int i=0;i<v[2].size();i++)
    {
        col[v[2][i]]=ansp[2];
    }
    cout<<ans<<endl;
    for(int i=1;i<=n;i++)
    {
        cout<<col[i]<<" ";
    }
    cout<<endl;
return 0;
}
