//ѹ�пδ�
#include<bits/stdc++.h>
#define LL long long
#define LD long double
using namespace std;
const int MAXN=1e5+10;
LL n,k;
pair<LL,LL> a[MAXN];
LL read(){LL sss=0,fff=1;char ccc;ccc=getchar();while(ccc<'0'||ccc>'9'){if(ccc=='-')fff=-1;ccc=getchar();}while(ccc>='0'&&ccc<='9')sss=(sss<<1)+(sss<<3)+(ccc^'0'),ccc=getchar();return sss*fff;}
template<typename T> inline void write(T x){if(!x) return;write(x/10);putchar((x%10)+'0');}
template<typename T> inline void wri(T x){write(x);puts("");}
int main()
{
//	freopen("123.in","r",stdin);
//	freopen("123.out","w",stdout);
	n=read();k=read();
	for(int i=1;i<=n;i++)
		a[i].first=read(),a[i].second=1;
	sort(a+1,a+1+n);
	int l=1,r=n;
	while(k)
	{
		while(l<r&&a[l].first==a[l+1].first)
			a[l+1].second+=a[l].second,l++;
		while(r>l&&a[r].first==a[r-1].first)
			a[r-1].second+=a[r].second,r--;
		if(l==r) break;
		if(a[l].second<a[r].second)
		{
			LL p=a[l+1].first-a[l].first;
			if(p*a[l].second<=k)
			{
				k-=p*a[l].second;
				a[l].first=a[l+1].first;
			}
			else
			{
				p=k/a[l].second;
				a[l].first+=p;
				k=0;
			}
		}
		else
		{
			LL p=a[r].first-a[r-1].first;
			if(p*a[r].second<=k)
			{
				k-=p*a[r].second;
				a[r].first=a[r-1].first;
			}
			else
			{
				p=k/a[r].second;
				a[r].first-=p;
				k=0;
			}
		}
	}
	printf("%lld\n",a[r].first-a[l].first);
	return 0;
}
