// by : 信冯哥
#include<bits/stdc++.h>
using namespace std;
const int maxn = (int)1e5+5;
const int mod = (int)1e9+7;

typedef long double dl;
typedef long long ll;
//#define int ll

#define orz cout<<endl
#define debug cout<<"-------------------"<<endl
#define input freopen("in.txt","r",stdin)
#define output freopen("out.txt","w",stdout)
#define sync ios::sync_with_stdio(false)
ll ans;
int n,m,k,l,s,t,r,T;
ll c[4][maxn];
int du[maxn];
vector<int>edge[maxn];
int fa[maxn];
int son[maxn];

int ca[maxn];
void dfs(int x,int pre)
{
    fa[x]=pre;
    son[pre]=x;
    for(int i:edge[x])
        if(i!=pre)
            dfs(i,x);
}

void work(int x)
{
    for(int j=1;j<=3;j++)
        if(j!=ca[fa[x]]&&j!=ca[fa[fa[x]]])
        {
            ca[x]=j;
            break;
        }
    ans+=c[ca[x]][x];
    if(son[x])
        work(son[x]);
}
int out[maxn];
int main()
{

	sync;
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>c[1][i];
    for(int i=1;i<=n;i++)
        cin>>c[2][i];
    for(int i=1;i<=n;i++)
        cin>>c[3][i];
    for(int i=1;i<n;i++)
    {
        cin>>l>>r;
        du[l]++;
        du[r]++;
        edge[l].push_back(r);
        edge[r].push_back(l);
    }
    int root;
    for(int i=1;i<=n;i++) {
        if (du[i] >= 3) {
            cout << -1 << endl;
            return 0;
        }
        if(du[i]==1)
            root=i;
    }
    dfs(root,0);
    ll us=LLONG_MAX;
    for(int i=1;i<=3;i++)
        for(int j=1;j<=3;j++){
            if(i==j)
                continue;
            ans=0;
            ca[root]=i;
            ca[son[root]]=j;
            ans=c[i][root]+c[j][son[root]];
            work(son[son[root]]);
            if(ans<us)
            {
                us=ans;
                for(int k=1;k<=n;k++)
                    out[k]=ca[k];
            }
        }

    cout<<us<<endl;

        for(int i=1;i<=n;i++)
            cout<<out[i]<<" ";
    return 0;
}

