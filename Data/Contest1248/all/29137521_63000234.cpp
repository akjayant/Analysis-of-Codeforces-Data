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

const long long MOD=1000000007;

int main()
{
	long long N=Sonoda::read<long long>();
	long long M=Sonoda::read<long long>();
	long long a=1,b=1;
	for(int i=1;i<=N+1-2;i++)
	{
		long long t=a;
		t%=MOD;
		a=a+b;
		a%=MOD;
		b=t;
		b%=MOD;
	}
	a*=2;
	a%=MOD;
	long long ans=0;
	long long a1=1,b1=0;
	if(M==1)
	{
		ans=0;
	}
	else if(M==2)
	{
		ans=1;
	}
	else
	{
		for(int i=1;i<=M-1;i++)
		{
			ans+=a1;
			ans%=MOD;
			long long t=a1;
			t%=MOD;
			a1=a1+b1;
			a1%=MOD;
			b1=t;
			b1%=MOD;
		}
	}
	ans*=2;
	a1*=2;
	printf("%I64d",(a+ans)%MOD);
	return 0;
}
