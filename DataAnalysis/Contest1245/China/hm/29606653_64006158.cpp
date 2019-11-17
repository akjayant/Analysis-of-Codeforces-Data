using namespace std;

const int maxn=100003;
const int mo=1e9+7;
int n,f[maxn][2],g[maxn],res=1;
char s[maxn];

int main(){
 scanf("%s",s+1);
 n=strlen(s+1);
 g[0]=1;
 f[1][0]=1;g[1]=1;
 for(int i=2;i<=n;++i){
  f[i][0]=g[i-1];
  f[i][1]=f[i-1][0];
  g[i]=(f[i][0]+f[i][1])%mo;
 }
 int len=0;
 for(int i=1;i<=n;++i){
  if(s[i]=='m'||s[i]=='w'){
   puts("0");
   return 0;
  }
  if(s[i]!=s[i-1]){
   res=(1ll*res*g[len])%mo;
   len=0;
  }
  if(s[i]=='u'||s[i]=='n')
   ++len;
 }
 res=(1ll*res*g[len])%mo;
 printf("%d\n",res);
 return 0;
}
