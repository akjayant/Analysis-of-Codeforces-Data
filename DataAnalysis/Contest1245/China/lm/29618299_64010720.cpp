using namespace std;
int n,mod=1e9+7;
char s[111111];
long long f[111111],ans=1;
int main(){
 cin>>s+1,n=strlen(s+1),f[0]=1,f[1]=2,f[2]=3;
 for(int i=1;i<=n;i++)if(s[i]=='w'||s[i]=='m'){printf("0");return 0;}
 for(int i=3;i<=n;i++)f[i]=f[i-1]+f[i-2],f[i]%=mod;
 for(int i=1,res=0;i<=n+1;i++){
  if(s[i]!='u'&&s[i-1]=='u')ans*=f[res-1],ans%=mod,res=0;
  if(s[i]=='u')res++;
 }
 for(int i=1,res=0;i<=n+1;i++){
  if(s[i]!='n'&&s[i-1]=='n')ans*=f[res-1],ans%=mod,res=0;
  if(s[i]=='n')res++;
 }
 printf("%I64d",ans);
}
