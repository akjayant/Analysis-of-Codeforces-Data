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

int T,n,pos1,pos2,cnt;
char s[MAXN+5],t[MAXN+5];
int main()
{
    T=read();
    while(T--){
        cnt=0;
        n=read();
        scanf("%s%s",s+1,t+1);
        for(int i=1;i<=n;i++){
            if(s[i]!=t[i]){
                cnt++;
                if(cnt==1)pos1=i;
                if(cnt==2)pos2=i;
            }
        }
        //printf("%d %d\n",pos1,pos2);
        if(cnt==0)printf("YES\n");
        else if(cnt==2&&s[pos1]==s[pos2]&&t[pos2]==t[pos1])
        printf("YES\n");
        else printf("NO\n");
    }
}
