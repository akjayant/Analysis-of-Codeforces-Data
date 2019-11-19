#include<cstdio>
#include<cctype>
#include<algorithm>
using namespace std;
typedef long long LL;
const int maxn=1e5+5;
const int INF=0x3f3f3f3f;
const LL MOD=1e9+7;

template<typename Tp>
inline bool read(Tp *x){
  *x=0;char c;bool f=0;
  while(!isdigit(c=getchar())){if(!~c)return 0;if(c=='-')f=1;}
  while(isdigit(c))*x=*x*10+c-'0',c=getchar();
  if(f)*x=-*x;return 1;
}
inline bool readstr(char *s){
  char c;while((c=getchar())<=32)if(!~c)return 0;
  while(c>32)*s++=c,c=getchar();*s=0;return 1;
}

LL f[maxn],g[maxn][2][2];
int n,m;
LL powmod(LL a,LL b,LL c){
  LL ans=1;
  for(a%=c;b;b>>=1,a=a*a%c)if(b&1)ans=ans*a%c;
  return ans;
}
int main(){
  read(&n),read(&m);f[0]=f[1]=1;
  for(int i=2;i<=n;i++)f[i]=(f[i-1]+f[i-2])%MOD;
  g[1][0][0]=2;
  g[1][0][1]=(f[n]-1+MOD)%MOD*2%MOD;
  for(int i=2;i<=m;i++){
    g[i][0][0]=(g[i-1][0][0]+g[i-1][1][0])%MOD;
    g[i][1][0]=g[i-1][0][0];
    g[i][0][1]=g[i-1][0][1];
    g[i][1][1]=g[i-1][1][1];
  }
  //for(int i=1;i<=m;i++)printf("g[%d][0]=%lld, g[%d][1]=%lld\n",i,g[i][0],i,g[i][1]);
  printf("%lld\n",(g[m][0][0]+g[m][1][0]+g[m][0][1]+g[m][1][1])%MOD);
  return 0;
}