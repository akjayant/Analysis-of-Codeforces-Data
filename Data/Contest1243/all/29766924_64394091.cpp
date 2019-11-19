#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<queue>
#include<vector>
#include<stack>
#include<map>
#include<deque>
#include<set>
#define inf 1e9
#define eps 1e-6
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
inline ll read()
{
	char ch=getchar();
	ll s=0,w=1;
	while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){s=s*10+ch-'0';ch=getchar();}
	return s*w;
}
ll n;
ll flag,wch,num;
int main()
{
	n=read();ll x=n;if(n==1){printf("1\n");return 0;}
	for(register ll i=2;i<=sqrt(x);i++)
	{
		if(n%i==0){flag++;num=i;while(n%i==0)n/=i;}
	}
	if(n>1){flag++;num=n;}
	if(flag>1){printf("1\n");}
	else printf("%I64d\n",num);
	return 0;
}
