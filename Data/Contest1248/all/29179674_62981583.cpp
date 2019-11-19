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

LL a[maxn];
int n;
int main(){
  read(&n);
  for(int i=1;i<=n;i++)read(&a[i]);
  sort(a+1,a+1+n);
  LL sum1=0,sum2=0;
  for(int i=1;i<=n;i++)sum1+=a[i];
  for(int i=n/2+1;i<=n;i++)sum2+=a[i];
  printf("%lld\n",sum2*sum2+(sum1-sum2)*(sum1-sum2));
  return 0;
}