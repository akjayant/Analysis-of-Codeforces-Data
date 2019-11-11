#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long LL;
const int maxn=1e5+5;
const LL MOD=1e9+7;
char s[maxn];
LL powmod(LL a,LL b,LL c){
  LL ans=1;
  for(a%=c;b;b>>=1,a=a*a%c)if(b&1)ans=ans*a%c;
  return ans;
}
LL f[maxn];
int main(){
  scanf("%s",s+1);
  int n=strlen(s+1);f[0]=f[1]=1;
  for(int i=2;i<=n;i++)f[i]=(f[i-1]+f[i-2])%MOD;
  LL ans=1;int cnt=0;
  for(int i=1;i<=n;i++){
    if(s[i]=='m'||s[i]=='w')return puts("0"),0;
    if(s[i]=='n'||s[i]=='u'){
      cnt++;
      if(s[i+1]!=s[i])ans=ans*f[cnt]%MOD,cnt=0;
    }
  }
  printf("%lld\n",ans);
  return 0;
}