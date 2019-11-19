#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define v vector<ll> 
#define vv vector<v>
#define p pair<ll,ll>
ll LIM=1e5+100;
vv adj(LIM);
v vec(1);
void dfs(ll n,ll par)
{
    vec.push_back(n);
    for (ll i=0; i<adj[n].size(); i++)
    {
        if (adj[n][i]==par)
            continue;
        dfs(adj[n][i],n);
    }
}
int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);    
    ll n;
    cin>>n;
    vv color(n+1,v(5,0));
    for (ll i=0; i<3;i++)
    {
        for (ll j=1; j<=n; j++)
            cin>>color[j][i];
    }
    for (ll i=1; i<n; i++)
    {
        ll a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    ll start=-1;

    for (ll i=1; i<=n; i++)
    {
        if (adj[i].size()>2)
        {
            cout<<-1<<endl;
            return 0;
        }   
        if (adj[i].size()==1)
            start=i;
    }
    dfs(start,start);
    vv C2(n+1,v(5,0));
    for (ll i=1; i<=n; i++)
    {
        for (ll j=0; j<3; j++)
            C2[i][j]=color[vec[i]][j];
    }
    ll ans=1e17;
    ll first=-1,second=-1;
    for (ll i=0; i<3; i++)
    {
        for (int j=0; j<3; j++)
        {
            if (i==j)
                continue;
            int third=3-i-j;
            ll temp=0;
            for (ll k=1; k<=n; k++)
            {
                int c=-1;
                if ((k-1)%3==0)
                    c=i;
                else if ((k-1)%3==1)
                    c=j;
                else
                    c=third;
                temp=temp+C2[k][c];
            }
            if (temp<ans)
            {
                ans=temp;
                first=i;
                second=j;
            }
        }
    }    
    cout<<ans<<endl;
    v b(n+1,0);
    for (ll i=1; i<=n; i++)
    {
        int c=-1;
        if ((i-1)%3==0)
            c=first;
        else if ((i-1)%3==1)
            c=second;
        else
            c=3-first-second;        
        b[vec[i]]=c+1;
    }
    for (int i=1; i<=n; i++)
        cout<<b[i]<<" ";

    return 0;
}