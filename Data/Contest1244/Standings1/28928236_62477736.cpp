#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long n,p,w,d,x;
    scanf("%lld%lld%lld%lld",&n,&p,&w,&d);
    for(x=0;x<w && x*d<=p && x<=n;x++)
    {
    	if((p-x*d)%w==0 && x+(p-x*d)/w<=n)
    	{
    		printf("%lld %lld %lld\n",(p-x*d)/w,x,n-(x+(p-x*d)/w));
    		return 0;
		}
	}
	printf("-1\n");
	return 0;
}
