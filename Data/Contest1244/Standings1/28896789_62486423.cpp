#include<bits/stdc++.h>
#define maxn 100005
#define pii pair<int,int>
#define ll long long
#define pll pair<ll,ll>
#define mod 1000000007
#define pb push_back
using namespace std;


ll digni(ll x,ll y)
{
    if(y==0)return 1;
    if(y%2==0)
    {
        ll res=digni(x,y/2);
        return (res*res)%mod;
    }
    return (digni(x,y-1)*x)%mod;
}

int n;
ll c[maxn][3];
vector<int>adj[maxn];

bool bio[maxn];
vector<int>v;
int poz[maxn];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin>>n;
    for(int i=0;i<3;i++)
    {
        for(int v=1;v<=n;v++)
        {
            cin>>c[v][i];
        }
    }

    for(int i=1;i<n;i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    int start;
    for(int i=1;i<=n;i++)
    {
        bio[i]=false;
        if(adj[i].size()==1)
        {
            start=i;
        }
        if(adj[i].size()>=3)
        {
            cout<<"-1\n";
            return 0;
        }
    }


    bio[start]=true;
    while(true)
    {
        v.pb(start);
        int poc=start;
        for(auto x:adj[start])
        {
            if(!bio[x])
            {
                bio[x]=true;
                start=x;
            }
        }

        if(poc==start)break;
    }

    /*for(auto x:v)cout<<x<<" ";
    cout<<endl;*/


    int boja[6][3];

    boja[0][0]=0;
    boja[0][1]=1;
    boja[0][2]=2;

    boja[1][0]=0;
    boja[1][1]=2;
    boja[1][2]=1;

    boja[2][0]=1;
    boja[2][1]=0;
    boja[2][2]=2;

    boja[3][0]=1;
    boja[3][1]=2;
    boja[3][2]=0;

    boja[4][0]=2;
    boja[4][1]=0;
    boja[4][2]=1;

    boja[5][0]=2;
    boja[5][1]=1;
    boja[5][2]=0;

    ll zbir[6];
    int minn=0;
    for(int col=0;col<6;col++)
    {
        zbir[col]=0;
        for(int i=0;i<n;i++)
        {
            zbir[col]+= c[ v[i] ][ boja[col][i%3] ];
        }

        if(zbir[minn]>zbir[col])
        {
            minn=col;
        }

        //cout<<"stoka"<<endl;
    }

    for(int i=0;i<n;i++)
    {
        poz[v[i]]=i;
    }

    //cout<<"milivoje"<<endl;

    cout<<zbir[minn]<<"\n";
    for(int i=1;i<=n;i++)
    {
        cout<<boja[minn][poz[i]%3]+1<<" ";
    }

    return 0;
}
