#include<cstdio>
#include<cctype>
#include<algorithm>
using namespace std;
typedef long long LL;
const int maxn=1e5+5;
const int INF=0x3f3f3f3f;

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

int p[maxn],q[maxn],t,n,m;
int main(){
  read(&t);
  while(t--){
    int cntp=0,cntq=0;
    read(&n);
    for(int i=1;i<=n;i++)read(&p[i]),cntp+=p[i]&1;
    read(&m);
    for(int i=1;i<=m;i++)read(&q[i]),cntq+=q[i]&1;
    printf("%lld\n",1ll*cntp*cntq+1ll*(n-cntp)*(m-cntq));
  }
  return 0;
}