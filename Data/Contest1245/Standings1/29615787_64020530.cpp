#include<cstdio>
#include<cstring>
#define add(a,b) a=(a+b)%mod;
#define mod 1000000007
using namespace std;
long long ans=1,f[100500];
char str[100500];
int main()
{
  scanf("%s",str+1);
  int n=strlen(str+1);
  f[0]=f[1]=1;
  for (int i=1;i<=n;i++)
    f[i]=(f[i-2]+f[i-1])%mod;
  for (int i=1,p=1;i<=n;i++){
    if (str[i]!='n'&&str[i]!='u')p=i+1;
    if (str[i]=='w'||str[i]=='m')
      {ans=0;break;}
    else if (str[i]=='n'&&str[i+1]!='n'){
      ans=(ans*f[i-p+1])%mod;
      p=i+1;
    }else if (str[i]=='u'&&str[i+1]!='u'){
      ans=(ans*f[i-p+1])%mod;
      p=i+1;
    }
  }printf("%I64d",ans);
  return 0;
}
