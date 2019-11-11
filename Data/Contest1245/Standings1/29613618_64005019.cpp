#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+100;
const int P = 1e9+7;
#define fr(i,a,b) for(register int i = a;i <= b; ++i)

char s[N];
int f[N];

int main(){
   f[0] = f[1] = 1;
   fr(i,2,N-1)f[i] = (f[i-1]+f[i-2])%P;

   scanf("%s",s+1);
   int n = strlen(s+1);
   int nn = 0,uu = 0;
   int ans = 1;
   fr(i,1,n)
      if(s[i] == 'n'){
         ++nn;
         if(uu)ans = 1LL*ans*f[uu]%P,uu = 0;
      } else if(s[i] == 'u'){
         ++uu;
         if(nn)ans = 1LL*ans*f[nn]%P,nn = 0;
      } else {
         if(s[i] == 'm' || s[i] == 'w')ans = 0;
         if(nn)ans = 1LL*ans*f[nn]%P,nn = 0;
         if(uu)ans = 1LL*ans*f[uu]%P,uu = 0;
      }
   if(nn)ans = 1LL*ans*f[nn]%P;
   if(uu)ans = 1LL*ans*f[uu]%P;
   printf("%d\n",ans);
   return 0;
}
