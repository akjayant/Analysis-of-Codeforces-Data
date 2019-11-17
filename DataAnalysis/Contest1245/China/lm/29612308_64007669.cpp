using namespace std;

const int N=1e5+5,MOD=1e9+7;

int n,fib[N],ans=1;

char s[N];

char qwq[N],lc;int cnt[N],ccnt=-1,lst;

int plu(int u,int v){
 return (u+v)%MOD;
}

int mul(int u,int v){
 return (int)(1LL*u*v%MOD);
}

int main(){
 fib[0]=fib[1]=1;
 for(int i=2;i<=1e5;i++){
  fib[i]=plu(fib[i-1],fib[i-2]);
 }
 scanf("%s",s+1);
 n=(int)strlen(s+1);
 for(int i=1;i<=n;i++){
  if(s[i]=='w'||s[i]=='m'){
   printf("0\n");
   return 0;
  }
 }
 for(int i=1;i<=n+1;i++){
  if(s[i]^lc){
   ++ccnt;cnt[ccnt]=i-lst;lst=i;qwq[ccnt]=lc;lc=s[i];
  }
 }
 for(int i=1;i<=ccnt;i++){
  if(qwq[i]=='u'||qwq[i]=='n'){
   ans=mul(ans,fib[cnt[i]]);
  }
 }
 printf("%d\n",ans);



 return 0;
}
