#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;
namespace Sonoda
{
	template<typename T> void swap(T &a,T &b)
	{
		T t;
		t=a;
		a=b;
		b=t;
	}
	template<typename T> T GCD(T a,T b)
	{
		if(b==0)
		{
			return a;
		}
		return GCD(b,a%b);
	}
	template<typename T>T Qpow(T a,T b,T p)
	{
		T res=1;
		while(b)
		{
			if(b&1)
			{
				res*=a;
				res%=p;
				b--;
			}
			else
			{
				a*=a;
				a%=p;
				b>>=1;
			}
		}
		return res;
	}
	template <typename T> void Ex_GCD(T a,T b,T &x,T &y)
	{
		if(b==0)
		{
			x=1;
			y=0;
			return;
		}
		Ex_GCD(b,a%b,x,y);
		T t=x;
		x=y;
		y=t-a/b*y;
	}
	template<typename T> inline T read()
	{
		T num = 0, w = 1;
		char c = 0;
		while (c != '-' && !isdigit(c)) c = getchar();
		if (c == '-') w = -1, c = getchar();
		while (isdigit(c)) num = num * 10 + c - '0', c = getchar();
		return num * w;
	}
	template<typename T> inline void write(T x)
	{
		if (x < 0) putchar('-'), x = -x;
		if (x / 10) write(x / 10);
		putchar(x % 10 + '0');
	}
}
const long long MAXN=1000005;
long long a[MAXN],b[MAXN];
long long sum1,sum2;
long long num1,num2;
long long ans;
int main()
{
	long long T=Sonoda::read<long long>();
	while(T--)
	{
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		sum1=sum2=0;
		num1=num2=0;
		long long N=Sonoda::read<long long>();
		for(long long i=1;i<=N;i++)
		{
			a[i]=Sonoda::read<long long>();
			if(a[i]%2==0)
			{
				sum2++;
			}
			else
			{
				sum1++;
			}
		}
		long long M=Sonoda::read<long long>();
		for(long long i=1;i<=M;i++)
		{
			b[i]=Sonoda::read<long long>();
			if(b[i]%2==0)
			{
				num2++;
			}
			else
			{
				num1++;
			}
		}
		printf("%lld\n",sum1*num1+sum2*num2);
	}
	return 0;
}
