#include <bits/stdc++.h>
using namespace std;
const int Nxc = 1e6;
inline char nc()
{
	static char buf[Nxc],*p1=buf,*p2=buf;
	return p1==p2&&(p2=(p1=buf)+fread(buf,1,Nxc,stdin),p1==p2)?EOF:*p1++;
}
inline int read()
{
	int w=1,d=0; char ch=nc();
	while(ch<'0'||ch>'9'){if(ch=='-')w=-1; ch=nc();}
	while(ch>='0'&&ch<='9') d=(d<<3)+(d<<1)+(ch^48),ch=nc();
	return w*d;
}
const int N = 1e4;
int n,a[N];
int main()
{
	int T=read();
	while(T--)
	{
		int a=read(),b=read();
		bool flag=0;
		if(__gcd(a,b)!=1) cout<<"Infinite";
		else cout<<"Finite";
		cout<<endl;
	}
	return 0;
} 