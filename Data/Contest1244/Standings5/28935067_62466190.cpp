#include<bits/stdc++.h>
#define mp make_pair
#define pb push_back
using namespace std;
typedef long long LL;
typedef unsigned int uint;
typedef pair<int,int> pii;
//-------------------------------------------------------------------LYYY↓
namespace LYYY{
	int rd()
	{
		int s=0;char c=getchar();int f=1;
		while(c<48||c>57)
		{
			if(c==45) f=-1;
			c=getchar();
		}
		while(c>=48&&c<=57) s=(s<<3)+(s<<1)+(c^48),c=getchar();
		return s*f;
	}
	LL rdl()
	{
		LL s=0;char c=getchar();int f=1;
		while(c<48||c>57)
		{
			if(c==45) f=-1;
			c=getchar();
		}
		while(c>=48&&c<=57) s=(s<<3)+(s<<1)+(c^48),c=getchar();
		return s*f;
	}
	void wt(int x)
	{
		if(x>=10) wt(x/10);
		putchar(x%10+48);
	}
	void WT(int x)
	{
		if(x<0) x=-x,putchar(45);
		wt(x);
	}
	void wtl(LL x)
	{
		if(x>=10) wtl(x/10);
		putchar(x%10+48);
	}
	void WTL(LL x)
	{
		if(x<0) x=-x,putchar(45);
		wtl(x);
	}
}using namespace LYYY;
//-------------------------------------------------------------------bianliang↓
//-------------------------------------------------------------------hanshu↓
//-------------------------------------------------------------------main()↓
int main()
{
	int T=rd();
	while(T--)
	{
		int a=rd(),b=rd(),c=rd(),d=rd(),k=rd();
		if((a-1)/c+1+(b-1)/d+1<=k) WT((a-1)/c+1),putchar(32),WT((b-1)/d+1),puts("");
		else puts("-1");
	}
	return 0;
}