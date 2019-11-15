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
int n,sl,fh,a[310][310];
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
	n=rd();int x=1,y=1,d=n,dx=1;
	for(int i=1;i<=n*n;++i)
	{
		a[x][y]=i;
		if(x==d) y++,dx=-dx,d=n+1-d;
		else x+=dx;
	}
	for(int i=1;i<=n;++i,puts(""))
		for(int j=1;j<=n;++j)
			printf("%d ",a[i][j]);
	return 0;
}