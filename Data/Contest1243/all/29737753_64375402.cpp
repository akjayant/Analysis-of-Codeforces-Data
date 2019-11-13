#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mod 1000000007
main()
{
    int q;
    scanf("%d",&q);
    while(q--){
   int n,i,a=1;
   scanf("%d",&n);
   int ara[n];
   for(i=0;i<n;i++)
   {
       scanf("%d",&ara[i]);
   }
   sort(ara,ara+n);
   reverse(ara,ara+n);
   for(i=0;i<n;i++)
   {
      if(ara[i]>=a)
      {
          a++;
      }
      else
      {
          break;
      }
   }
   printf("%d\n",a-1);
    }
}
