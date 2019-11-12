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
const int inf=1e9,mod=998244353;
int x,y,z,sl,fh,ans;
int rd()
{
	sl=0;fh=1;
	char ch=getchar();
	while(ch<'0'||'9'<ch) {if(ch=='-') fh=-1; ch=getchar();}
	while('0'<=ch&&ch<='9') sl=sl*10+ch-'0',ch=getchar();
	return sl*fh;
}
int main()
{
	for(int res,T=rd();T;--T)
	{
		x=rd();y=rd();z=rd();ans=0;
		for(int i=0;i<=x&&i*2<=y;++i)
		{
			res=3*i+3*min(y-i*2,z/2);
			ans=max(ans,res);
		}
		printf("%d\n",ans);
	}
	return 0;
}