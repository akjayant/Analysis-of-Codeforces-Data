/*
@Date    : 2019-10-20 17:19:44
@Author  : Adscn (adscn@qq.com)
@Link    : https://www.cnblogs.com/LLCSBlog
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define IL inline
#define RG register
#define gi geti<int>()
#define gl geti<ll>()
#define gc getchar()
#define File(a) freopen(a".in","r",stdin);freopen(a".out","w",stdout)
template<typename T>IL bool chkmax(T &x,const T &y){return x<y?x=y,1:0;}
template<typename T>IL bool chkmin(T &x,const T &y){return x>y?x=y,1:0;}
template<typename T>
IL T geti()
{
	RG T xi=0;
	RG char ch=gc;
	bool f=0;
	while(!isdigit(ch))ch=='-'?f=1:f,ch=gc;
	while(isdigit(ch))xi=xi*10+ch-48,ch=gc;
	return f?-xi:xi;
}
template<typename T>
IL void pi(T k,char ch=0)
{
	if(k<0)k=-k,putchar('-');
	if(k>=10)pi(k/10);
	putchar(k%10+'0');
	if(ch)putchar(ch);
}
/*
IL unsigned int LOG2(unsigned int x)
{
	unsigned int ret;
	__asm__ __volatile__ ("bsrl %1, %%eax":"=a"(ret):"m"(x));
	return ret;
}
*/
ll f[100001][4],g[100001][4];
const int P=1e9+7;
inline ll dp(auto f,int n)
{
	if(n==1)return 2;
	f[2][0]=f[2][1]=f[2][2]=f[2][3]=1;
	for(int i=3;i<=n;++i)
	{
		f[i][0]=f[i-1][2];
		f[i][1]=(f[i-1][2]+f[i-1][3])%P;
		f[i][2]=(f[i-1][1]+f[i-1][0])%P;
		f[i][3]=f[i-1][1];
	}
	return ((f[n][0]+f[n][1])%P+(f[n][2]+f[n][3])%P)%P;
}
int main(void)
{
	int n=gi,m=gi;
	pi(((dp(f,n)%P+dp(g,m)%P-2)%P+P)%P);
	return 0;
}