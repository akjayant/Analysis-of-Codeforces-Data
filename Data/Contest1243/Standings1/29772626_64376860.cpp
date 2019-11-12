#include<iostream>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
inline int read()
{
	int neg=1,num=0;char c=getchar();
	for(;!isdigit(c);c=getchar())if(c=='-')neg=-1;
	for(;isdigit(c);c=getchar())num=(num<<1)+(num<<3)+c-'0';
	return neg*num;
}
int T,n,ans,a[1010];
int main()
{		
	T=read();
	while(T--)
	{
		n=read();ans=0;
		for(int i=1;i<=n;i++)a[i]=-read();
		sort(a+1,a+n+1);
		for(int i=1;i<=n;i++)ans=max(ans,min(i,-a[i]));
		cout<<ans<<endl;
	}
	return 0;
}

