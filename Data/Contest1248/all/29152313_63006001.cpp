#pragma GCC optimize(3)
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<ctime>
#include<vector>
#include<queue>
#include<algorithm>
#include<string>
#include<sstream>
#include<cctype>
#include<cmath>
#include<iomanip>
#include<map>
#include<stack>
#include<set>
#include<functional>
#define in(x) x=read()
#define qr read()
//#define int ll
#define mp make_pair
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
namespace fastIO
{
    #define BUF_SIZE 100000
    bool IOerror=0;
    inline char nc()
	{
        static char buf[BUF_SIZE],*p1=buf+BUF_SIZE,*pend=buf+BUF_SIZE;
        if (p1==pend){
            p1=buf; pend=buf+fread(buf,1,BUF_SIZE,stdin);
            if (pend==p1){IOerror=1;return -1;}
        }
        return *p1++;
    }
    inline bool blank(char ch){return ch==' '||ch=='\n'||ch=='\r'||ch=='\t';}
    inline ll read()
	{
        bool sign=0; char ch=nc();ll x=0;
        for (;blank(ch);ch=nc());
        if (IOerror)return 0;
        if (ch=='-')sign=1,ch=nc();
        for (;ch>='0'&&ch<='9';ch=nc())x=x*10+ch-'0';
        if (sign)x=-x;
        return x;
    }
    #undef BUF_SIZE
};
using namespace fastIO;
int num[1000];
char t[10000],s[10000];
int f,l,q[10010];
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	int n,maxx=-1e16,maxi,maxj;
	cin>>n;
	cin>>s+1;
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			for(int i=1;i<=n;i++)t[i]=s[i];
			swap(t[i],t[j]);
			for(int i=1;i<=n;i++)t[n+i]=t[i];
			f=1,l=0;
			int ans=0,now=0;
			for(int k=1;k<2*n;k++)
			{
				if(t[k]=='(')now++;
				else now--;
				num[k]=now;
				while((f<=l)&&(num[k]<num[q[l]]))l--;
				q[++l]=k;
				while((f<=l)&&(q[f]<=k-n))f++;
				if(k>=n)
				{
				//	cout<<i<<" "<<j<<" "<<k<<" "<<*s.begin()<<"\n";
					if(now==num[k-n]&&num[q[f]]==num[k-n])ans++;
				}
			}
			if(ans>maxx)maxx=ans,maxi=i,maxj=j;
		}
	}
	cout<<maxx<<'\n'<<maxi<<' '<<maxj<<'\n';
	return 0;
}