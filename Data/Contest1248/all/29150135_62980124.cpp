#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
int p[100007],q[100007];
inline int read()
{
	int x=0;char ch;ch=getchar();
	while(ch<'0' or ch>'9') ch=getchar();
	while(ch>='0' and ch<='9') x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
	return x;
}
inline void readArray(int a[],int n)
{
	for(int i=1;i<=n;i++) a[i]=read();
} 
signed main()
{
	int T;
	T=read();
	while(T--)
	{
		int E=0,O=0,e=0,o=0;
		n=read();
		readArray(p,n);
		m=read();
		readArray(q,m);
		for(int i=1;i<=n;i++)
		{
			if(p[i]%2==1) E++;
			else O++;
		}
		for(int i=1;i<=m;i++)
		{
			if(q[i]%2==1) e++;
			else o++;
		}
//		cout<<O<<" "<<o<<" "<<E<<" "<<e<<endl;
		printf("%lld\n",O*o+E*e);
	}
}

