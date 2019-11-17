using namespace std;
typedef long long ll;
const int M = 1200000;
const int md = 1e9+7;
int n,m,k;
char s[M];
int dp[M]={0};
int solve(){
 for(int i=(1);i<=(n);++i) if(s[i]=='m'||s[i]=='w') return 0;
 ll ans=1;
 for(int i=(1);i<=(n);++i) {
  int c=1;
  if(s[i]=='n'){
  while(i+1<=n&&s[i+1]=='n') {
   ++i;++c;
  }
  }
  ans*=dp[c];
  ans%=md;
  c=1;
  if(s[i]=='u'){
  while(i+1<=n&&s[i+1]=='u'){
   ++i;++c;
  }
  }
  ans*=dp[c];
  ans%=md;
 }
 return ans;
}
int main() {
 cin>>(s+1);
 n = strlen(s+1);
 dp[0]=dp[1]=1;
 for(int i=(2);i<=(n);++i) dp[i]=(dp[i-2]+dp[i-1])%md;
 cout<<solve()<<endl;
 return 0;
}
