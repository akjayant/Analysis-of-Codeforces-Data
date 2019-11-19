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
int n,sl,fh,ans;
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
		n=rd();scanf("%s",s+1);ans=n;
		for(int i=1;i<=n;++i)
			if(s[i]=='1')
				ans=max(ans,2*i),
				ans=max(ans,2*(n-i+1));
		printf("%d\n",ans);
	}
	return 0;
}