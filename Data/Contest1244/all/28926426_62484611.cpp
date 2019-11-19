#include<bits/stdc++.h>
#define LL long long
using namespace std;
LL x,y,l,r;
LL n,k;
LL a[234234];

int main()
{
  LL i;
  scanf("%lld%lld",&n,&k);
  for(i=1;i<=n;i++) scanf("%lld",&a[i]);
  sort(a+1,a+1+n);
  x=a[1],y=a[n],l=1,r=n;
  while(x<y && k)
    {
	  if(l<(n-r+1))
	    {
		  if((a[l+1]-a[l])*l<=k) 
		    k-=(a[l+1]-a[l])*l,x=a[l+1],l++;
		  else {x+=k/l;break;} 
		}
	  else
	    {
		  if((a[r]-a[r-1])*(n-r+1)<=k)
		    k-=(a[r]-a[r-1])*(n-r+1),y=a[r-1],r--;
		  else {y-=k/(n-r+1);break;}
		}
	}
  printf("%lld",y-x);
} 