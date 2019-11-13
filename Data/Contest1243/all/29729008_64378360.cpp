#include <bits/stdc++.h>

using namespace std;
 
int num[1200];
int qian[1200];

int main() {
int t;
cin>>t;
while (t--)
{
   int n;
   scanf("%d",&n);
   memset(qian,0,sizeof(qian));
   for (int a=1;a<=n;a++)
      scanf("%d",&num[a]);
   sort(num+1,num+n+1);
   reverse(num+1,num+n+1);
   int cnt=n;
   int ans=n;
   for (int a=1;a<=n;a++)
   {
      for (int b=1;b<=n;b++)
         if (num[b]<a)
         {
            cnt=b-1;
            break;
			}
	   if (cnt<a)
	   {
	      ans=a-1;
	      break;
		}
	}
	printf("%d\n",ans);
}
	return 0;
}