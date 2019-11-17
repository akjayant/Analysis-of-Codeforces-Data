using namespace std;

typedef long long ll;
const int MAXN=100005;
const ll MOD=1e9+7;

char ch[MAXN];
int n;
ll dp[MAXN],pre[MAXN];

int main(){


 scanf("%s",ch+1);
 n=strlen(ch+1);
 ch[0]='#';
 ch[n+1]='@';
 dp[1]=0;
 dp[0]=1;
 pre[0]=1;
 pre[1]=1;
 for (register int i=2;i<=n;++i){
  dp[i]=pre[i-2];
  pre[i]=(pre[i-1]+dp[i])%MOD;
 }

 int su=0,sn=0;
 ll ans=1;
 for (register int i=1;i<=n+1;++i){
  if (ch[i]=='w' || ch[i]=='m'){
   printf("0");
   return 0;
  }
  if (ch[i]=='u'){
   su++;
  }
  else{
   ans=(ans*pre[su])%MOD;
   su=0;
  }
  if (ch[i]=='n'){
   sn++;
  }
  else{
   ans=(ans*pre[sn])%MOD;
   sn=0;
  }
 }
 cout<<ans;
 return 0;
}
