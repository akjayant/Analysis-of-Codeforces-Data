#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
#include<stack>
#include<cmath>
#include<cstring>
using namespace std;
#define MAXN 500000
#define MOD 998244353
#define DB double
#define LL long long
#define Pr pair<int,int>
#define X first
#define Y second
LL read(){
   	LL x=0,F=1;char c=getchar();
    while(c<'0'||c>'9'){if(c=='-')F=-1;c=getchar();}
   	while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}
    return x*F;
}
int n,a[MAXN+5];
LL x,y;
int main()
{
	n=read();
	for(int i=1;i<=n;i++){
		a[i]=read();y+=a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n/2;i++){
		x+=a[i];
	}
	printf("%lld",x*x+(y-x)*(y-x));
}