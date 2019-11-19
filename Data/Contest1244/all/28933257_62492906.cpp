#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define f(i,n) for(int i=0;i<n;i++)
ll c[100100][3],d[100100][6],a[100100],vis[100100],ans[8];
vector<ll >adj[100100];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,u,v;
    cin >> n;
    for(int i=1;i<=n;i++)
        cin >> c[i][0];
    for(int i=1;i<=n;i++)
        cin >> c[i][1];
    for(int i=1;i<=n;i++)
        cin >> c[i][2];
    f(i,n-1)
    {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    ll f=0,s;
    for(int i=1;i<=n;i++)
    {
        if(adj[i].size()>=3)
            {
                f=1;
                break;
            }
        if(adj[i].size()==1)
            s=i;
    }
    if(f==1)
        {
            cout << -1 << endl;
            return 0;
        }
    queue<ll> q;
    q.push(s);
    ll k=0;
    while(!q.empty())
    {
        ll v=q.front();
        vis[v]=1;
        q.pop();
        //cout << q.size() << endl;
        for(ll i=0;i<adj[v].size();i++)
        {
            u = adj[v][i];
            if(vis[u]==0)
                q.push(u);
        }
        a[k++]=v;
    }
    int qq[] = {0,1,2};
    int qw[] = {0,2,1};
    int qe[] = {1,0,2};
    int qr[] = {1,2,0};
    int qt[] = {2,1,0};
    int qy[] = {2,0,1};
    for(ll i=0;i<k;i++)
    {
        d[a[i]][0] = qq[i%3];
        ans[0] += c[a[i]][qq[i%3]]; 

        d[a[i]][1] = qw[i%3]; 
        ans[1] += c[a[i]][qw[i%3]];        
        
        d[a[i]][2] = qe[i%3]; 
        ans[2] += c[a[i]][qe[i%3]]; 
        
        d[a[i]][3] = qr[i%3]; 
        ans[3] += c[a[i]][qr[i%3]]; 
        
        d[a[i]][4] = qt[i%3]; 
        ans[4] += c[a[i]][qt[i%3]]; 
        
        d[a[i]][5] = qy[i%3];
        ans[5] += c[a[i]][qy[i%3]]; 

    }
    ll minn = 100000000000000000,ind;
    for(int i=0;i<6;i++)
    {
        if(ans[i]<minn)
        {
            minn = ans[i];
            ind =  i; 
        }
    }
    cout << minn << endl;
    for(ll i=1;i<=n;i++)
    {
        cout << d[i][ind]+1 << " ";
    }
    cout << endl;

	return 0;
}