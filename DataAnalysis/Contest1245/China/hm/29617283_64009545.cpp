using namespace std;

long long t,n,k,l,r,a,b,c,ans,sum,dp[1000050];
char s[1000050];

int main()
{
 std::ios::sync_with_stdio(false);
 cin.tie(0);
 cin>>s;
 if(s[0]=='w'||s[0]=='m')
 {
  cout<<0;
  return 0;
 }
 n=strlen(s);
 dp[0]=dp[1]=1;
 for(int i=1;i<n;i++)
 if(s[i]=='w'||s[i]=='m')
 n=0;
 else
 if(s[i]==s[i-1]&&(s[i]=='u'||s[i]=='n'))
 dp[i+1]=(dp[i-1]+dp[i])%1000000007;
 else
 dp[i+1]=dp[i];
 if(n)
 cout<<dp[n];
 else
 cout<<0;
 return 0;
}
