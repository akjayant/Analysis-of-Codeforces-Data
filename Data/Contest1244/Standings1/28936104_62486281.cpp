#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
#include <cmath>
#include <map>
#include <stack>
#include <set>
#include <sstream>
#include <vector>
#include <stdlib.h>
#include <algorithm>
//ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
//#pragma comment(linker, "/STACK:10240000,10240000")
using namespace std;

#define dbg(x) cout<<#x<<" = "<< (x)<< endl
#define dbg2(x1,x2) cout<<#x1<<" = "<<x1<<" "<<#x2<<" = "<<x2<<endl
#define dbg3(x1,x2,x3) cout<<#x1<<" = "<<x1<<" "<<#x2<<" = "<<x2<<" "<<#x3<<" = "<<x3<<endl
#define max3(a,b,c) max(a,max(b,c))
#define min3(a,b,c) min(a,min(b,c))

typedef pair<int,int> pll;
typedef long long ll;
typedef unsigned long long ull;
const ull hash1 = 201326611;
const int inf = 0x3f3f3f3f;
const int _inf = 0xc0c0c0c0;
const ll INF = 0x3f3f3f3f3f3f3f3f;
const ll _INF = 0xc0c0c0c0c0c0c0c0;
const ll mod =  (int)1e9+7;

ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
ll ksm(ll a,ll b,ll mod){int ans=1;while(b){if(b&1) ans=(ans*a)%mod;a=(a*a)%mod;b>>=1;}return ans;}
ll inv2(ll a,ll mod){return ksm(a,mod-2,mod);}
void exgcd(ll a,ll b,ll &x,ll &y,ll &d){if(!b) {d = a;x = 1;y=0;}else{exgcd(b,a%b,y,x,d);y-=x*(a/b);}}//printf("%lld*a + %lld*b = %lld\n", x, y, d);
//ull ha[MAX_N],pp[MAX_N];

inline int read()
{
    int date = 0,m = 1; char ch = 0;
    while(ch!='-'&&(ch<'0'|ch>'9'))ch = getchar();
    if(ch=='-'){m = -1; ch = getchar();}
    while(ch>='0' && ch<='9')
    {
        date = date*10+ch-'0';
        ch = getchar();
    }return date*m;
}

/*namespace sgt
{
    #define mid ((l+r)>>1)

    #undef mid
}*/

/*int root[MAX_N],cnt,sz;
namespace hjt
{
    #define mid ((l+r)>>1)
    struct node{int l,r,maxx;}T[MAX_N*40];

    #undef mid
}*/
const int MAX_N = 100025;
vector<int> vt[MAX_N];
int indeg[MAX_N],ANS[MAX_N],ck[5];
ll sum[3][3],col[3][MAX_N];
void dfs(int x,int fa,int dep)
{
    sum[dep][0]+=col[0][x];
    sum[dep][1]+=col[1][x];
    sum[dep][2]+=col[2][x];
    for(int i= 0;i<vt[x].size();++i)
    {
        int v = vt[x][i];
        if(v==fa) continue;
        dfs(v,x,(dep+1)%3);
    }
}
void DFS(int x,int fa,int dep)
{
    ANS[x] = ck[dep];
    for(int i= 0;i<vt[x].size();++i)
    {
        int v = vt[x][i];
        if(v==fa) continue;
        DFS(v,x,(dep+1)%3);
    }
}
int main()
{
    //ios::sync_with_stdio(false);
    //freopen("a.txt","r",stdin);
    //freopen("b.txt","w",stdout);
    int n,a,b;
    scanf("%d",&n);
    for(int i = 1;i<=n;++i)
        scanf("%lld",&col[0][i]);
    for(int i = 1;i<=n;++i)
        scanf("%lld",&col[1][i]);
    for(int i = 1;i<=n;++i)
        scanf("%lld",&col[2][i]);
    for(int i = 1;i<n;++i)
    {
        scanf("%d%d",&a,&b);
        vt[a].push_back(b);
        vt[b].push_back(a);
        indeg[a]++;
        indeg[b]++;
    }
    int st;
    bool flag = true;
    for(int i = 1;i<=n;++i)
    {
        if(indeg[i]>2)
        {
            flag = false;
            break;
        }
        if(indeg[i]==1)
        {
            st = i;
        }
    }
    if(!flag)
    {
        puts("-1");
        return 0;
    }
    else
    {
        dfs(st,-1,0);
    }
    ll ans = min(min(min(sum[0][2]+sum[1][1]+sum[2][0],sum[0][2]+sum[1][0]+sum[2][1]),min(sum[0][0]+sum[1][1]+sum[2][2],sum[0][0]+sum[1][2]+sum[2][1])),min(sum[0][1]+sum[1][0]+sum[2][2],sum[0][1]+sum[1][2]+sum[2][0]));
    printf("%lld\n",ans);
    if(ans==sum[0][0]+sum[1][1]+sum[2][2])
    {
        ck[0] = 1;
        ck[1] = 2;
        ck[2] = 3;
    }
    else if(ans==sum[0][0]+sum[1][2]+sum[2][1])
    {
        ck[0] = 1;
        ck[1] = 3;
        ck[2] = 2;
    }
    else if(ans==sum[0][1]+sum[1][0]+sum[2][2])
    {
        ck[0] = 2;
        ck[1] = 1;
        ck[2] = 3;
    }
    else if(ans==sum[0][1]+sum[1][2]+sum[2][0])
    {
        ck[0] = 2;
        ck[1] = 3;
        ck[2] = 1;
    }
    else if(ans==sum[0][2]+sum[1][0]+sum[2][1])
    {
        ck[0] = 3;
        ck[1] = 1;
        ck[2] = 2;
    }
    else if(ans==sum[0][2]+sum[1][1]+sum[2][0])
    {
        ck[0] = 3;
        ck[1] = 2;
        ck[2] = 1;
    }
    DFS(st,-1,0);
    for(int i = 1;i<=n;++i)
        printf("%d ",ANS[i]);
    //fclose(stdin);
    //fclose(stdout);
    //cout << "time: " << (long long)clock() * 1000 / CLOCKS_PER_SEC << " ms" << endl;
    return 0;
}
