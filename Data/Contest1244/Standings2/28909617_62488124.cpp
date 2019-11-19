#include <bits/stdc++.h>
using namespace std;
#define sc(x)            scanf("%d",&x)
#define scc(x)           scanf("%c",&x)
#define scl(x)           scanf("%lld",&x)
#define sz(v)	     	(v.size())
#define mem(v, d)		memset(v, d, sizeof(v))
#define oo				2000000100
#define OO				2000000000000000100
#define PI 3.14159265
#define s second
#define f first
#define Ceil(x,y) ((x+y-1)/y)
#define EPS 1e-8
#define IO ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
const double pi=3.14159265358979323846264338327950288419716939937510582097494459;
typedef unsigned int uint;
typedef long long ll;
int dX[] = {0,0,1,-1,0};
int dY[] = {1,-1,0,0,0};
string alpha = "abcdefghijklmnopqrstuvwxyz";
const int N = 100100;
const int MOD = 1e9 + 7;
int n,cst[N][3],col[N];
vector<int>adj[N];
vector<int>vec;
void dfs(int cur,int par=0)
{
    vec.push_back(cur);
    for(auto x:adj[cur])
        if(x!=par)
            dfs(x,cur);
}
ll calc(vector<int>& tmp)
{
    ll ret = 0; int i = 0;
    for(auto x:vec)
        col[x] = tmp[i],ret+=cst[x][tmp[i]],i = (i+1)%3;
    return ret;
}
int main()
{
#ifndef ONLINE_JUDGE
      //freopen("in.txt","r",stdin);
#else
    //freopen("journey.in","r",stdin);
    //freopen("journey.out","w",stdout);
#endif
    sc(n);
    for(int j = 0;j<3;++j)
        for(int i = 1;i<=n;++i)
            sc(cst[i][j]);
    for(int i = 1;i<n;++i){
        int u,v; sc(u); sc(v);
        adj[u].push_back(v);
        adj[v].push_back(u);
        if(sz(adj[u])>2) return puts("-1");
        if(sz(adj[v])>2) return puts("-1");
    }
    int root = 1;
    for(int i = 1;i<=n;++i)
        if(sz(adj[i])==1){
            root = i;
            break;
        }
    dfs(root);
    vector<int>per;
    for(int i = 0;i<3;++i)
        per.push_back(i);
    ll out = OO;
    vector<int>ch;
    do
    {
        ll tmp = calc(per);
        if(tmp < out) ch = per,out = tmp;
    }while(next_permutation(per.begin(),per.end()));
    calc(ch);
    printf("%lld\n",out);
    for(int i = 1;i<=n;++i)
        printf("%d%c",col[i]+1," \n"[i==n]);







    return 0;
}
