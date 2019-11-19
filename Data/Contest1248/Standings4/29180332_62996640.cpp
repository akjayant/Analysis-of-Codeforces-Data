#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef pair<int,int> PII;
typedef pair<ll,ll> Pll;
typedef vector<int> VI;
typedef vector<PII> VII;
//typedef pair<ll,ll>P;
#define N  200010
#define M  100
#define fi first
#define se second
#define MP make_pair
#define pb push_back
#define pi acos(-1)
#define mem(a,b) memset(a,b,sizeof(a))
#define rep(i,a,b) for(int i=(int)a;i<=(int)b;i++)
#define per(i,a,b) for(int i=(int)a;i>=(int)b;i--)
#define lowbit(x) x&(-x)
#define Rand (rand()*(1<<16)+rand())
#define id(x) ((x)<=B?(x):m-n/(x)+1)
#define ls p<<1
#define rs p<<1|1

const ll MOD=1e9+7,inv2=(MOD+1)/2;
      double eps=1e-6;
      ll INF=1e15;
      int dx[4]={-1,1,0,0};
      int dy[4]={0,0,-1,1};

      ll f[N],a[N];


int read()
{
   int v=0,f=1;
   char c=getchar();
   while(c<48||57<c) {if(c=='-') f=-1; c=getchar();}
   while(48<=c&&c<=57) v=(v<<3)+v+v+c-48,c=getchar();
   return v*f;
}

int main()
{
    int n=read(),m=read();
    //if(n>m) swap(n,m);
    a[1]=2; a[2]=4;
    rep(i,3,n) a[i]=(a[i-1]+a[i-2])%MOD;
    f[1]=a[n]; f[2]=(f[1]+2)%MOD; f[3]=(f[2]+2)%MOD;
    rep(i,4,m)
    {
        f[i]=(f[i-1]*2%MOD-f[i-3]+MOD)%MOD;
        f[i]=(f[i]%MOD+MOD)%MOD;
    }
    printf("%I64d\n",f[m]);

    return 0;
}
