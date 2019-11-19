#include<iostream>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<algorithm>
#define int long long
using namespace std;
inline int read()
{
	int neg=1,num=0;char c=getchar();
	for(;!isdigit(c);c=getchar())if(c=='-')neg=-1;
	for(;isdigit(c);c=getchar())num=(num<<1)+(num<<3)+c-'0';
	return neg*num;
}
int n,ans;
inline int gcd(int x,int y)
{
	if(x%y!=0)return gcd(y,x%y);
	else return y;
}
signed main()
{
	n=read();ans=n;
	for(int i=2;i<=sqrt(n);i++)if(n%i==0)ans=gcd(ans,gcd(i,n/i));
	cout<<ans;
	return 0;
}
