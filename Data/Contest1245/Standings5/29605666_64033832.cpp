#include<bits/stdc++.h>
using namespace std;

#define fi(i,a,b)    for(long long i=a;i<=b;i++)
#define fr(i,a)      for(long long i=0;i<a;i++)
#define fd(i,a,b)    for(long long i=b;i>=a;i--)
#define clr(x)       memset(x,0,sizeof(x))
#define cln(x)       memset(x,-1,sizeof(x))
#define __           printf(" ")
#define _            printf("\n")
#define _o           printf("1\n")
#define stree        long long lft=node<<1,rht=(node<<1)|1,mid=(s+e)>>1
#define snode        long long s,long long e,long long node
#define slft         s,mid,lft
#define srht         mid+1,e,rht
#define sin()        if(S<=s&&e<=E)
#define sout()       if(S>e||s>E)
#define mod          1000000007
#define read()       freopen("in.txt","r",stdin)
#define write()      freopen("out.txt","w",stdout)
#define sfl(x)       scanf("%I64d",&x)
#define sfll(x,y)    scanf("%I64d %I64d",&x,&y)
#define sflll(x,y,z) scanf("%I64d %I64d %I64d",&x,&y,&z)
#define pfl(x)       printf("%I64d",x)
#define pfll(x,y)    printf("%I64d %I64d",x,y)
#define pflll(x,y,z) printf("%I64d %I64d %I64d",x,y,z)
#define xx           100000

typedef long long ll;
typedef pair<long long,long long> pll;


long long mem[xx+10];


char s[xx+10];

main(){
   mem[0]=mem[1]=1;
   fi(i,2,xx) mem[i]=(mem[i-2]+mem[i-1])%mod;

   scanf("%s",s);
   long long len=strlen(s),pre=0,ans=1;

   fi(i,0,len-1)
   if(s[i]=='m'||s[i]=='w'){
      ans=0;
      break;
   }
   else if(s[i]=='n'||s[i]=='u') {
       if(i==0) {
            pre=1;
            continue;
       }

       if(s[i]==s[i-1]) pre++;
       else{
          if(pre) ans=(ans*mem[pre])%mod;
          //if(ans==0) cout<<i<<endl;
          pre=1;
       }
   }
   else{
      if(pre) ans=(ans*mem[pre])%mod;
      pre=0;
   }

   if(pre) ans=(ans*mem[pre])%mod;

   cout<<ans<<endl;



   return 0;
}
