#include<bits/stdc++.h>
#define mxn 4000010
#define db double
#define LL long long
#define ldb long double
#define pb push_back
#define ppb pop_back
#define pf push_front
#define pii pair<int,int> 
#define mp make_pair
#define fr first
#define sc second
#define x1 faqx1
#define y1 faqy1
#define x2 faqx2
#define y2 faqy2
using namespace std;
const int inf=1e9,mod=1e9+7;
int n,m,sl,fh;
int rd()
{
	sl=0;fh=1;
	char ch=getchar();
	while(ch<'0'||'9'<ch) {if(ch=='-') fh=-1; ch=getchar();}
	while('0'<=ch&&ch<='9') sl=sl*10+ch-'0',ch=getchar();
	return sl*fh;
}
int _pow(int k,int i)
{
	int t=1;
	for(;i;i>>=1,k=1ll*k*k%mod)
		if(i&1)
			t=1ll*t*k%mod;
	return t;
}
int main()
{
	n=rd();m=rd();
	printf("%d\n",_pow(_pow(2,m)-1,n));
	return 0;
}