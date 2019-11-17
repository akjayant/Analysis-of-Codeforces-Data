using namespace std;
typedef long long ll;
char s[100010];
const ll P=1e9+7;
ll dp[100010];
int main(){
 scanf("%s",s+1);
 ll len=strlen(s+1);
 dp[0]=1;
 for(ll i=1;i<=len;i++){
  if(s[i]=='m'||s[i]=='w'){
   printf("0");
   return 0;
  }
  if(s[i]=='u'&&s[i-1]=='u') dp[i]=(dp[i-1]+dp[i-2])%P;
  else{
   if(s[i]=='n'&&s[i-1]=='n') dp[i]=(dp[i-1]+dp[i-2])%P;
   else dp[i]=dp[i-1]%P;
  }
 }
 printf("%lld",dp[len]);
}
