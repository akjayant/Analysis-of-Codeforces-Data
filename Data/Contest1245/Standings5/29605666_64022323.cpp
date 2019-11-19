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
#define mod          1000000000007
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


long long mem[35][2][2][2][2];
long long s,e;

bool r,cha,chb;

void calc_zero(long long x,long long y,bool a,bool b){
     cha=a,chb=b,r=true;
     if(y==1&&b==false) r=false;

     if(x==1) cha=true;
     return;
}


void calc_one(long long x,long long y,bool a,bool b){
    cha=a,chb=b,r=true;
    if(x==0&&a==false)r=false;

    if(y==0) chb=true;
    return;
}

long long dp(long long cur,bool a,bool b,bool u,bool v){
     if(cur<0) return 1;
     long long &ret=mem[cur][a][b][u][v];

     if(ret!=-1) return ret;ret=0;

     long long x=((1ll<<cur)&e)?1:0;
     long long y=((1ll<<cur)&s)?1:0;

     bool r1,a1,b1;

     fi(i,0,1) fi(j,0,1) {
         if(i==1&&j==1) break;

         if(i==0) calc_zero(x,y,a,b);
         else calc_one(x,y,a,b);
         r1=r,a1=cha,b1=chb;

         if(j==0) calc_zero(x,y,u,v);
         else calc_one(x,y,u,v);

         if(r==true&&r1==true) ret=ret+dp(cur-1,a1,b1,cha,chb);
     }
     return ret;
}


main(){
   long long t;
   cin>>t;
   while(t--){
      sfll(s,e);
      cln(mem);
      cout<<dp(33,false,false,false,false)<<endl;
   }
   return 0;
}
