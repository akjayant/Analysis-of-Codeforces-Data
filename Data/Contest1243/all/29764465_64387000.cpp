/*Lower_Rating*/
/*CF 599 A*/
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<set>
#include<vector>
#include<map>
using namespace std;

#define LL long long
#define MAXN 800000
#define MAXM 2000000
#define MOD 998244353
#define Pr pair<int,int>
#define X first
#define Y second
#define INF 1000000000000000000
#define mem(x,p) memset(x,p,sizeof(x))

LL read(){
  LL x=0,F=1;char c=getchar();
  while(c<'0'||c>'9'){if(c=='-')F=-1;c=getchar();}
  while(c>='0'&&c<='9'){x=(x<<3)+(x<<1)+c-'0';c=getchar();}
  return x*F;
}

int add(int x,int y){return (x+y>=MOD)?x+y-MOD:x+y;}
int dec(int x,int y){return (x-y<0)?x-y+MOD:x-y;}
int mul(int x,int y){return 1LL*x*y%MOD;}

LL n,rt,cnt;
int main()
{
    n=read();
    for(LL i=2;i*i<=n;i++)
    if(n%i==0){
        while(n%i==0)n/=i;
        rt=i;
        cnt++;
    }
    if(n!=1){rt=n,cnt++;}
    if(cnt==1)printf("%lld",rt);
    else printf("1\n");
}
