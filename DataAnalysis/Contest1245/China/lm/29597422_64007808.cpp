using namespace std;
const long long mod=1e9+7;
long long n,m,t,res,dp[100050];
char a[100005];
main(){
 scanf("%s",a+1);
 n=strlen(a+1);
 if(!n || (n==1 && (a[1]>'z'|| a[1]<'a'))){
  cout<<0; return 0;
 }
 for(long long i=1;i<=n;i++){
  if(a[i]=='m' || a[i]=='w'){
   cout<<0;return 0;
  }
 }
 dp[0]=dp[1]=1;
 for(long long i=2;i<=n;i++){
  if((a[i]=='n' && a[i-1]=='n') || (a[i]=='u' && a[i-1]=='u')) dp[i]=(dp[i-2]+dp[i-1])%mod;
  else dp[i]=dp[i-1];

 }
 printf("%lld",dp[n]);
 return 0;
}
