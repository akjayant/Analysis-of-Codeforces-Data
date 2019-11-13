#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long LL;
const int maxn=100+5;
int T,n,a,b,c;
char s[maxn],t[maxn];
//R>S  S>P  P>R
int main(){
  scanf("%d",&T);
  while(T--){
    scanf("%d%d%d%d%s",&n,&a,&b,&c,s+1);
    int lim=n+1>>1,cnt=0;
    memset(t,0,sizeof(t));
    for(int i=1;i<=n;i++){
      if(s[i]=='R'&&b>0)cnt++,b--,t[i]='P';
      if(s[i]=='P'&&c>0)cnt++,c--,t[i]='S';
      if(s[i]=='S'&&a>0)cnt++,a--,t[i]='R';
    }
    if(cnt<lim){puts("NO");continue;}
    puts("YES");
    for(int i=1;i<=n;i++){
      if(t[i])putchar(t[i]);
      else if(a>0)putchar('R'),a--;
      else if(b>0)putchar('P'),b--;
      else putchar('S');
    }
    putchar('\n');
  }
  return 0;
}