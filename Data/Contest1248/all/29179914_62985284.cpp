#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#ifdef DEB
#define D if(1)
#else
#define D if(0)
#endif

const int NMAX = 1123456;
ll a[NMAX];
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%lld",a+i);
	sort(a,a+n);
	ll outa=0;
	ll outb=0;
	int mid=n/2;
	for(int i=0;i<mid;i++) outa+=a[i];
	for(int i=mid;i<n;i++) outb+=a[i];
	printf("%lld",outa*outa+outb*outb);
	return 0;
}
