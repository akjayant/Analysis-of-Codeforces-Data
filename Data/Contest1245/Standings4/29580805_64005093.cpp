#include<bits/stdc++.h>
using namespace std;
#define ll long long int
char ans[109];
int main()
{
    ll a,b,c,d,e,i,j,k,l,n,m,x,y,t,p;
     scanf("%lld",&t);
     string st;
     for(p=1;p<=t;p++)
     {
         scanf("%lld",&n);
         for(i=0;i<=n;i++)
         {
             ans[i]='.';
         }
         scanf("%lld%lld%lld",&a,&b,&c);
         cin>>st;
         x=n/2;
         if(n%2==1)
         {
             x++;
         }
         y=0;
         for(i=0;i<n;i++)
         {
             if(st[i]=='R' && b>0)
             {
                 y++;
                 ans[i]='P';
                 b--;
             }
             if(st[i]=='P' && c>0)
             {
                 c--;
                 y++;
                 ans[i]='S';
             }
             if(st[i]=='S' && a>0)
             {
                 a--;
                 y++;
                 ans[i]='R';
             }
         }
         if(y>=x)
         {
             printf("YES\n");
             for(i=0;i<n;i++)
             {
                 if(ans[i]=='.')
                 {
                     if(a>0)
                     {
                         a--;
                         ans[i]='R';
                     }
                     else if(b>0)
                     {
                         b--;
                         ans[i]='P';
                     }
                     else if(c>0)
                     {
                         c--;
                         ans[i]='S';
                     }
                 }
                 printf("%c",ans[i]);
             }
             printf("\n");
         }
         else
         {
             printf("NO\n");
         }
     }
}
