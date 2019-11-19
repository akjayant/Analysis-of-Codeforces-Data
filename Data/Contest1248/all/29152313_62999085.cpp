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
#define int ll
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
#define mod 1000000007
int sub[1000010],num[1000010],fir[1000010],sec[1000010];
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	int n=qr,m=qr;
	sub[1]=0,sub[2]=2;
	fir[1]=2,fir[2]=4;
	sec[1]=4,sec[2]=6,sec[3]=8;
	for(int i=3;i<=n;i++)sub[i]=sub[i-1]+sub[i-2]+2,sub[i]%=mod,fir[i]=fir[i-1]+fir[i-2],fir[i]%=mod;
	for(int i=4;i<=n;i++)sec[i]=2*sec[i-1]-sec[i-3],sec[i]%=mod,sec[i]+=mod,sec[i]%=mod;
	num[1]=fir[n],num[2]=sec[n];
	for(int i=3;i<=m;i++)num[i]=((num[i-1]+num[i-2]-sub[n])%mod+mod)%mod;
	cout<<num[m];
	return 0;
}