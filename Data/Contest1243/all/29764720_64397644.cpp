#include<bits/stdc++.h>
using namespace std;
#define int long long
#define forinc(i,a,b) for(int i=a;i<=b;++i)
#define fordec(i,a,b) for(int i=a;i>=b;--i)
#define forv(i,x) for(auto &i:x)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rnd(int l,int r)
{
    return l+rng()%(r-l+1);
}
#define in ({int x=0;int c=getchar(),n=0;for(;!isdigit(c);c=getchar()) n=(c=='-');for(;isdigit(c);c=getchar()) x=x*10+c-'0';n?-x:x;})
#define pii pair<int,int>
#define fi first
#define se second
#define batbit(i,x) (x|(1ll<<i))
#define getbit(i,x) ((x>>i)&1)

const int mn=1e6+100;
int e[mn+100],p[mn+100],np,x[mn],y[mn],k,n,res=1;

void nto()
{
    forinc(i,1,mn) e[i]=i;
    forinc(i,2,mn) if(e[i]==i)
    {
        for(int j=2*i;j<=mn;j+=i) e[j]=i;
    }
    np=0;
    forinc(i,2,mn) if(e[i]==i) p[++np]=i;
}

void phantich(int n)
{
    k=0;
    int i=1;
    int a;
    while(n>1000000)
    {
        while(p[i]<=n/p[i]&&n%p[i]!=0) i++;
        if(p[i]>n/p[i]) a=n;
        else a=p[i];
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

int pw(int a,int i)
{
    int b=1;
    for(;i;i>>=1,a=a*a) if(i&1) b=b*a;
    return b;
}

main()
{
    nto();
    cin >> n;
    phantich(n);
    forinc(i,1,k)
    {
        if(pw(x[i],y[i])<=n-1) continue;
        int tmp=0;
        forinc(j,1,y[i]) if(pw(x[i],j)<=n-1)
        {
            tmp=j;
        }
        res*=pw(x[i],y[i]-tmp);
    }
    cout << res;
}
