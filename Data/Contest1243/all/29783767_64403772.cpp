#include<bits/stdc++.h>
#define forinc(i,a,b) for(int i=a;i<=b;++i)
#define forout(i,a,b) for(int i=a;i>=b;--i)
#define forv(a,b) for(auto &a:b)
#define pii pair<int,int>
#define fi first
#define se second
#define sz(s) (int)(s.size())
#define pb push_back
#define int long long
#define in ({int x=0;int c=getchar(),n=0;for(;!isdigit(c);c=getchar()) n=(c=='-');for(;isdigit(c);c=getchar()) x=x*10+c-'0';n?-x:x;})
#define bit(x,i) ((x>>i)&1)
#define batbit(x,i) (x|(1ll<<i))
#define tatbit(x,i) (x&~(1ll<<i))
#define task "1243C"
using namespace std;
const int N=1e6+100;
int e[N+15],dp[N+15],np,x[N],y[N],k,n,res=1,fre[N];
int poww(int a,int i)
{
    int tmp=1;
    for(;i;i>>=1,a=a*a) if(i&1) tmp=tmp*a;
    return tmp;
}
void snt()
{
    forinc(i,1,N) e[i]=i;
    forinc(i,2,N) if(e[i]==i)
    {
        for(int j=2*i;j<=N;j+=i) e[j]=i;
    }
    np=0;
    forinc(i,2,N) if(e[i]==i) dp[++np]=i;
}

void pti(int n)
{
    k=0;
    int i=1;
    int a;
    int ggg=1e6;
    while(n>ggg)
    {
        while(dp[i]<=n/dp[i]&&n%dp[i]!=0) i++;
        if(dp[i]>n/dp[i]) a=n;
        else a=dp[i];
        x[++k]=a;y[k]=0;
        while(n%a==0) ++y[k],n/=a;
    }
    while(n>1)
    {
        a=e[n];
        x[++k]=a;
        y[k]=0;
        while(n%a==0) ++y[k],n/=a;
    }
}
vector<int >ke[N];
void dfs(int u)
{
    fre[u]=1;
    forv(v,ke[u])
    {
        if(fre[v]==0) dfs(v);
    }
}
main()
{
	///freopen(task".inp","r",stdin);
	///freopen(task".out","w",stdout);
	forinc(i,1,1004) ke[i].push_back(i+1);
	forinc(i,1,1004) if(fre[i]==0) dfs(i);
    cin >> n;
    snt();
    pti(n);
    forinc(i,1,k)
    {
        if(poww(x[i],y[i])<=n-1) continue;
        int ppppppp=0;
        forinc(j,1,y[i]) if(poww(x[i],j)<=n-1)
        {
            ppppppp=j;
        }
        res*=poww(x[i],y[i]-ppppppp);
    }
    cout << res;
}
