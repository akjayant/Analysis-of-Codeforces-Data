using namespace std;
int dp[100005]; char str[100005];

inline int mo(int x){return x>=1000000007?x-1000000007:x;}

int main(){
 scanf("%s",str+1);
 int n=strlen(str+1);
 dp[0]=1; bool flag=0;
 for(int i=1;i<=n;i++){
  if(str[i]=='w' || str[i]=='m'){flag=1;break;}
  dp[i]=dp[i-1];
  if(str[i]=='n' && str[i-1]=='n') dp[i]=mo(dp[i]+dp[i-2]);
  if(str[i]=='u' && str[i-1]=='u') dp[i]=mo(dp[i]+dp[i-2]);
 }
 if(flag) cout<<0<<endl;
 else cout<<dp[n]<<endl;
 return 0;
}
