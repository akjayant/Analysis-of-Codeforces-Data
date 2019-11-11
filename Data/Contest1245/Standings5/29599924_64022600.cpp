#include<cstdio>
#include<cstring>
#define maxn 100007
#define mod 1000000007
using namespace std;
inline int pls(int a, int b) {int m=a+b;return m<mod?m:m-mod;}
char s[maxn];
int f[maxn]={1};
int main() {
  scanf("%s",s+1);
  int n=strlen(s+1);
  for(int i=1;i<=n;++i) {
    f[i]=f[i-1];
    if(s[i]=='m'||s[i]=='w') return puts("0"),0;
    if((s[i]=='n'||s[i]=='u')&&s[i]==s[i-1]) f[i]=pls(f[i-2],f[i]);
  }
  return printf("%d\n",f[n]),0;
}
