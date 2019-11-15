#include<cstdio>
#include<cstring>
#include<cctype>
#define maxn 107
int T,n,a,b,c;
char s1[maxn],s2[maxn];
int qread() {
  char c=getchar();int num=0,f=1;
  for(;!isdigit(c);c=getchar()) if(c=='-') f=-1;
  for(;isdigit(c);c=getchar()) num=num*10+c-'0';
  return num*f;
}
int main() {
  T=qread();
  while(T--) {
    memset(s2,0,sizeof(s2));
    n=qread(),a=qread(),b=qread(),c=qread();
    scanf("%s1",s1+1);
    int ans=0;
    for(int i=1;i<=n;++i) {
      if(s1[i]=='R'&&b) s2[i]='P',--b;
      if(s1[i]=='P'&&c) s2[i]='S',--c;
      if(s1[i]=='S'&&a) s2[i]='R',--a;
    }
    for(int i=1;i<=n;++i) ans+=(s2[i]!=0);
    for(int i=1;i<=n;++i) {
      if(s2[i]) continue;
      if(a) s2[i]='R',--a;
      else if(b) s2[i]='P',--b;
      else s2[i]='S',--c;
    }
    if(ans<(n+1)/2) puts("NO");
    else puts("YES"),puts(s2+1);
  }
  return 0;
}