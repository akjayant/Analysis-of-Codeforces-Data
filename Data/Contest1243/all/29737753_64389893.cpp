#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mod 1000000007
main()
{
    int q;
    scanf("%d",&q);
    while(q--){
    int n,i,j,cnt=0,a,b;
    scanf("%d",&n);
    char s[n+1],t[n+1];
    scanf("%s",s);
    scanf("%s",t);
    for(i=0;i<n;i++)
    {
       if(s[i]==t[i])
       {
         cnt++;
       }
    }
    if(cnt!=n-2)
    {
        printf("NO\n");
        continue;
    }
    for(i=0;i<n;i++)
    {
       if(s[i]!=t[i])
       {
         a=i;
       }
    }
    for(i=0;i<n;i++)
    {
       if(s[i]!=t[i] && i!=a)
       {
         b=i;
       }
    }
    if(s[a]==s[b] && t[a]==t[b])
    {
        printf("YES\n");
    }
    else
    {
        printf("NO\n");
    }
    }
}




