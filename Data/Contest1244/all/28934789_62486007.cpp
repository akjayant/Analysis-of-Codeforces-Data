#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
typedef long long ll;
ll read()
{
    ll x=0,f=1;
    char ch=getchar();
    while(ch-'0'<0||ch-'0'>9){if(ch=='-') f=-1;ch=getchar();}
    while(ch-'0'>=0&&ch-'0'<=9){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
ll n,p,d,w,x,y;
int main()
{
	cin>>n>>p>>w>>d;
	x=p/w,y=0;
	while(x>=(p/w)-d&&x>=0)
    {
        ll tmp=p-w*x;
		if(tmp%d==0)
        {
			y=tmp/d;
			if(x+y>n)
            {
                puts("-1");
                return 0;
            }
            else{
                printf("%lld %lld %lld\n",x,y,n-x-y);
			    return 0;                
            }
		}
        x--;
	}
	puts("-1");
	return 0;
}