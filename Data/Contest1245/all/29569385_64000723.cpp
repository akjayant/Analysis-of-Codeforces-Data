#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxn=2e5+10;
//int a[maxn];
ll mod=1e9+7;
ll qpow(ll a,ll n)
{
    ll ans=1;
    while(n)
    {
        if(n&1)
            ans=ans*a%mod;
        a=a*a%mod;
        n>>=1;
    }
    return ans;
}
char s[maxn];
char ans[maxn];
int main()
{
   int t;
   scanf("%d",&t);
   while(t--)
   {
       int n,a,b,c;
       int ok=0;
       scanf("%d",&n);
       scanf("%d%d%d",&a,&b,&c);
       scanf("%s",s);
       int len=strlen(s);
       for(int i=0;i<len;i++)
           ans[i]='0';
       int cnt=0;
       for(int i=0;i<len;i++)
       {
           if(s[i]=='R')
           {
               if(b)
               {
                   b--;
                   ans[i]='P';
                   cnt++;
               }
           }
           if(s[i]=='P')
           {
               if(c)
               {
                   c--;
                   ans[i]='S';
                   cnt++;
               }
           }
           if(s[i]=='S')
           {
               if(a)
               {
                   a--;
                   ans[i]='R';
                   cnt++;
               }
           }
       }
       if(cnt*2>=len)
       {
           printf("YES\n");
           for(int i=0;i<len;i++)
           {
               if(ans[i]=='0')
               {
                   if(a)
                   {
                       printf("R");
                       a--;
                   }
                   else if(b)
                   {
                       printf("P");
                       b--;
                   }
                   else if(c)
                   {
                       printf("S");
                       c--;
                   }
               }
               else printf("%c",ans[i]);
           }
           printf("\n");

       }
       else printf("NO\n");

   }

    return 0;
}