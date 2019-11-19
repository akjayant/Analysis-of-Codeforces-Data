#include<bits/stdc++.h>
#define ll long long
#define double long double
#define f(i, a, b) for(int i=(a);i<=(b);++i)
#define rf(i, a, b) for(int i=(a);i>=(b);--i)
#define Cl(a) memset(a,0,sizeof(a))
#define Cln(a) memset(a,0xff,sizeof(a))
#define cp(a, b) memcpy(a,b,sizeof(b))
#define sz(a) ((int)((a).size()))
#define pb emplace_back
#define sqr(x) ((x)*(x))
#define all(a) (a).begin(),(a).end()
#define mpr make_pair
#define x first
#define y second
#define Debug(a) cout<<"---"<<a<<"---"<<endl;
#define endl '\n'

using namespace std;
const int N=1e5+10;
map<int,bool> mp[N];
bitset<N> b;
int n,m,k,ans[N];
void dfs(int u)
{
    b[u]=0,ans[k]++;
    for (int i=b._Find_first();i<b.size();i=b._Find_next(i))
        if (!mp[u][i])
            dfs(i);
}
int main()
{
    ios::sync_with_stdio(0),cin.tie(0);
    int i;
    cin>>n>>m;
    for (i=1;i<=n;i++) b[i]=1;
    for (i=1;i<=m;i++)
    {
        int u,v;
        cin>>u>>v;
        mp[u][v]=mp[v][u]=true;
    }
    for (i=1;i<=n;i++) if (b[i]) dfs(i),++k;
    cout<<k-1<<endl;
}
