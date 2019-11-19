#include<bits/stdc++.h>
#define mxn 1000010
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
using namespace std;
const int mod=1e9+7;
int a,b,c,d,k,x,y,sl,fh;
char s[mxn];
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
	for(int T=rd();T;--T)
	{
		a=rd();b=rd();c=rd();d=rd();k=rd();x=y=-1;
		for(int i=0;i<=100;++i)
			for(int j=0;j<=100;++j)
				if(i+j<=k&&c*i>=a&&d*j>=b)
					{x=i,y=j; break;}
		if(x==-1) puts("-1");
		else printf("%d %d\n",x,y);
	}
	return 0;
}