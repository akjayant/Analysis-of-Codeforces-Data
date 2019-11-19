#include<algorithm>
#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<ctime>
#include<iomanip>
#include<iostream>
#include<map>
#include<queue>
#include<set>
#include<stack>
#include<vector>
#define rep(i,x,y) for(register int i=(x);i<=(y);++i)
#define dwn(i,x,y) for(register int i=(x);i>=(y);--i)
#define view(u,k) for(int k=fir[u];~k;k=nxt[k])
#define LL long long
using namespace std;
int read()
{
    int x=0,f=1;char ch=getchar();
    while(!isdigit(ch)&&ch!='-')ch=getchar();
    if(ch=='-')f=-1,ch=getchar();
    while(isdigit(ch))x=(x<<1)+(x<<3)+ch-'0',ch=getchar();
    return x*f;
}
void write(int x)
{
    if(x==0){putchar('0'),putchar('\n');return;}
    int f=0;char ch[20];
    if(x<0)putchar('-'),x=-x;
    while(x)ch[++f]=x%10+'0',x/=10;
    while(f)putchar(ch[f--]);
    putchar('\n');
    return;
}
int n,m,st0,st1,d;
const LL mod=1e9+7;
int mo(int x){return x>=mod?x-mod:x;}
int fib(int f0,int f1,int d,int x)
{
	if(x==1)return f0;
	rep(i,3,x)
	{
		f0=mo(mo(f0+f1)+d);
		swap(f0,f1);
	}
	return f1;
}
int main()
{
    //freopen(".in","r",stdin);
    //freopen(".out","w",stdout);
	n=read(),m=read();
	st0=fib(2,4,0,n),st1=st0+2,d=fib(0,2,2,n),d=mod-d;
	write(fib(st0,st1,d,m));
	//cout<<fib(1,1,0,5);
	return 0;
}