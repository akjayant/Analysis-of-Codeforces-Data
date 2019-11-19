#include<stdio.h>
#include<string.h>
#include<string>
#include<stdlib.h>
#include<math.h>
#include<algorithm>
#include<queue>
#include<stack>
#include<set>
#include<time.h>
#include<map>
#include<vector>
#include<iostream>
#include<assert.h>
using namespace std;
#define sca(a) scanf("%d",&a)
#define out(a) printf("%d\n",a)
#define mes(x,a); memset(x,a,sizeof(x));
#define lowbit(x)  x & (-x)
#define pb push_back
#define mk make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define pii pair<int, int>
typedef unsigned long long ull;
typedef long long ll;
const int maxn=1e5+5;
const int maxm=2e5+5;
const int inf =0x3f3f3f3f;
const ll mod=1e9+7;
const double eps=1e-9;
const double pi=acos(-1);
int m,n,w,k;
void init()
{

}
bool judge(int now)
{

}
ll quickpow(ll a,ll b)
{
    ll ans=1;
    while(b)
    {
        if(b&1)
            ans=ans*a%mod;
        a=a*a%mod;
        b>>=1;
    }
    return ans;
}
int a[maxn][5];
int degree[maxn];
vector<int>vec[maxn];
int ans[maxn];
void dfs(int now,int before)
{
    for(int i=0; i<vec[now].size(); i++)
    {
        int to=vec[now][i];
        if(to!=before)
        {
            for(int j=1; j<=3; j++)
            {
                if(j!=ans[now]&&j!=ans[before])
                {
                    ans[to]=j;
                    dfs(to,now);
                }
            }
        }
    }
}
int main()
{
    scanf("%d",&n);
    for(int i=1; i<=3; i++)
        for(int j=1; j<=n; j++)
            scanf("%d",&a[j][i]);
    int u,v;
    for(int i=1; i<n; i++)
    {
        scanf("%d%d",&u,&v);
        degree[u]++;
        degree[v]++;
        vec[u].pb(v);
        vec[v].pb(u);
    }
    for(int i=1; i<=n; i++)
        if(degree[i]>2)
        {
            printf("-1\n");
            return 0;
        }
    int root=0;
    for(int j=1; j<=n; j++)
        if(degree[j]==1)
        {
            root=j;
            break;
        }
    ll sum;
    ll small=1LL<<60;
    int k=0,l=0;
    int to=vec[root][0];
    for(int i=1; i<=3; i++)
    {
        sum=0;
        ans[root]=i;
        ans[to]=i%3+1;
        dfs(to,root);
        for(int j=1; j<=n; j++)
            sum+=a[j][ans[j]];
        if(sum<small)
        {
            k=i;
            l=ans[to];
            small=sum;
        }
        ans[to]=i-1;
        if(ans[to]==0)
            ans[to]=3;
        dfs(to,root);
        sum=0;
        for(int j=1; j<=n; j++)
            sum+=a[j][ans[j]];
        if(sum<small)
        {
            k=i;
            l=ans[to];
            small=sum;
        }
    }
    ans[root]=k;
    ans[to]=l;
    dfs(to,root);
    printf("%lld\n",small);
    for(int i=1; i<n; i++)
        printf("%d ",ans[i]);
    printf("%d\n",ans[n]);
}
