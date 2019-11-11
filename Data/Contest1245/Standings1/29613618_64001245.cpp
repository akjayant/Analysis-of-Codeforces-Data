#include<bits/stdc++.h>
using namespace std;
const int N = 110;
#define fr(i,a,b) for(register int i = a;i <= b; ++i)

int a,b,c,n;//R,P,S;
int t;
char s[N];
int vis[N];

void solve(){
   scanf("%d%d%d%d",&n,&a,&b,&c);
   scanf("%s",s+1);
   memset(vis,0,sizeof vis);
   int cnt = 0;
   fr(i,1,n){
      if(s[i] == 'R'){
         if(b)--b,s[i] = 'P',++cnt;
         else vis[i] = 1;
      }else if(s[i] == 'P'){
         if(c)--c,s[i] = 'S',++cnt;
         else vis[i] = 1;
      } else {
         if(a)--a,s[i] = 'R',++cnt;
         else vis[i] = 1;
      }
   }
   fr(i,1,n)if(vis[i]){
      if(a)--a,s[i] = 'R';
      else if(b)--b,s[i] = 'P';
      else --c,s[i] = 'S';
   }
   if(cnt >= ceil(n/2.0)){
      puts("YES");
      cout << s+1 << endl;
   } else {
      puts("NO");
   }
}

int main(){
   scanf("%d",&t);
   while(t--)solve();
}
