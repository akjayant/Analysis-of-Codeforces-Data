namespace csx_std {
 using namespace std;
 typedef long long ll;
 const int N=1e5+5;
 const int mod=1e9+7;
}
using namespace csx_std;
int n,ans=1,cnt,f[N];
char s[N];
int main()
{
 scanf("%s",s+1);
 n=strlen(s+1);
 f[1]=1;f[2]=2;
 for (register int i=(3);i<=(n);i++) f[i]=(f[i-1]+f[i-2])%mod;
 for (register int i=(1);i<=(n);i++){
  if(s[i]=='m' || s[i]=='w') return puts("0"),0;
  if(s[i]!=s[i-1]){
   if(s[i-1]=='u' || s[i-1]=='n') ans=1ll*ans*f[cnt]%mod;
   cnt=0;
  }
  cnt++;
 }
 if(s[n]=='u' || s[n]=='n') ans=1ll*ans*f[cnt]%mod;
 printf("%d\n",ans);
}
