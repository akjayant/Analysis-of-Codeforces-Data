#include <bits/stdc++.h>
using namespace std;
#define int long long
int hmt() {int x=0;int c=getchar(),n=0;for(;!isdigit(c);c=getchar()) n=(c=='-');for(;isdigit(c);c=getchar()) x=x*10+c-'0';return n?-x:x;}
#define in hmt()
#define forinc(i,a,b) for(int i=a;i<=b;i++)
#define fordec(i,a,b) for(int i=a;i>=b;i--)
#define fi first
#define se second
#define getbit(i,x) ((x>>i)&1ll)
#define ii pair<int,int>

const int maxn=1e6+5;
int E[maxn+100],P[maxn+100],cnt;
int X[maxn],Y[maxn],k,n;
int ret=1;
int poww(int a,int i)
{
    int b=1;
    for(;i;i>>=1,a=a*a) if(i&1) b=b*a;
    return b;
}
void snt()
{
    forinc(i,1,maxn) E[i]=i;
    forinc(i,2,maxn) if(E[i]==i)
    {
        for(int j=2*i;j<=maxn;j+=i) E[j]=i;
    }
    forinc(i,2,maxn) if(E[i]==i) P[++cnt]=i;
}
void hame(int n)
{
    k=0;
    int i=1;
    int a;
    while(n>1000000)
    {
        while(P[i]<=n/P[i]&&n%P[i]!=0) i++;
        if(P[i]>n/P[i]) a=n;
        else a=P[i];
        X[++k]=a;Y[k]=0;
        while(n%a==0) ++Y[k],n/=a;
    }
    while(n>1)
    {
        a=E[n];
        X[++k]=a;
        Y[k]=0;
        while(n%a==0) ++Y[k],n/=a;
    }
}
void solve()
{
    int s=0;
    while(s<24) s++;
}
main()
{
    //freopen("test.inp","r",stdin);
    ios_base::sync_with_stdio(false);
    snt();
    cin>>n;
    hame(n);
   // return 0;
    forinc(i,1,k)
    {
        if(poww(X[i],Y[i])<=n-1) continue;
        int tm=0;
        forinc(j,1,Y[i]) if(poww(X[i],j)<=n-1) tm=j;
        ret=ret*poww(X[i],Y[i]-tm);
    }
    cout<<ret;
}
