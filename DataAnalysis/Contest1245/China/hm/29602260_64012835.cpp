typedef long long ll;
typedef double db;
const int N = 1e5+100;
const ll mod = 1e9+7;
using namespace std;

char s[N];
ll f[N][2];

int main()
{
 scanf("%s",s+1);
 int len = strlen(s+1);
 for(int i = 1; i <= len; i++)
  if(s[i] == 'w' || s[i] == 'm'){
   printf("0\n");
   return 0;
  }
 f[0][0] = 1;
 for(int i = 1; i <= len; i++){
  f[i][0] = (f[i-1][0]+f[i-1][1])%mod;
  if(s[i] == s[i-1]){
   if(s[i] == 'u' || s[i] == 'n') f[i][1] = f[i-1][0];
  }
 }
 ll ans = f[len][0]+f[len][1];
 ans %= mod;
 printf("%lld\n",ans);
 return 0;
}
