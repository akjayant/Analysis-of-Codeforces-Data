#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mod 1000000007
main()
{
   ll n,i,cnt=0,a,x;
   scanf("%lld",&n);
   x=n;
   if(n%2==0)
   {
       cnt++;
       if(cnt==1)
       {
           a=2;
       }
     while(n%2==0)
     {
         n=n/2;
     }
   }
   for(i=3;i*i<=n;i++)
   {
       if(n%i==0)
       {
           cnt++;
           if(cnt==1)
           {
               a=i;
           }
           while(n%i==0)
           {
               n=n/i;
           }
       }
   }
   if(n>=2)
   {
       cnt++;
       if(cnt==1)
       {
           a=n;
       }
   }
   if(cnt>=2)
   {
       printf("1");
       return 0;
   }
   if(cnt==1)
   {
       printf("%lld",a);
       return 0;
   }
   if(cnt==0)
   {
       printf("%lld",n);
       return 0;
   }
}
