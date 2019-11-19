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
#include<stack>
#include<vector>
#define LL long long
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
#define dwn(i,x,y) for(int i=(x);i>=(y);--i)
#define view(u,k) for(int k=fir[u];~k;k=nxt[k])
#define maxn 2007
using namespace std;
int read()
{
	int x=0,f=1;char ch=getchar();
	while(!isdigit(ch)&&ch!='-')ch=getchar();
	if(ch=='-')f=-1,ch=getchar();
	while(isdigit(ch))x=(x<<1)+(x<<3)+ch-'0',ch=getchar();
	return x*f;
}
void write(LL x)
{
	char ch[20];int f=0;
	if(!x){putchar('0'),putchar('\n');return;}
	if(x<0)putchar('-'),x=-x;
	while(x)ch[++f]=x%10+'0',x/=10;
	while(f)putchar(ch[f--]);
	putchar('\n');
}
int n,c[maxn],w[maxn],nx[maxn],ny[maxn],bac[maxn];
LL to[maxn][maxn],dis[maxn],ww;
int main()
{
	n=read();
	memset(to,0x7f,sizeof(to));
	memset(dis,0x7f,sizeof(dis));
	rep(i,1,n)nx[i]=read(),ny[i]=read();
	rep(i,1,n)to[0][i]=to[i][0]=read();
	rep(i,1,n)w[i]=read();
	rep(i,1,n)rep(j,i+1,n)
	{
		LL d=(LL)(w[i]+w[j])*(abs(nx[i]-nx[j])+abs(ny[i]-ny[j]));
		to[i][j]=to[j][i]=d;
	}int now=0;dis[now]=0;
	while(now!=-1)
	{
		rep(i,1,n)if(dis[i]!=-1&&dis[i]>to[now][i])dis[i]=to[now][i],bac[i]=now;
		ww+=dis[now],dis[now]=-1,now=-1;
		rep(i,1,n)if(dis[i]!=-1&&(now==-1||dis[i]<dis[now]))now=i;
	}
	write(ww);int num1=0,num2=0;
	rep(i,1,n){if(bac[i])num2++;else num1++;}
	write(num1);
	rep(i,1,n)if(!bac[i])printf("%d ",i);puts("");
	write(num2);
	rep(i,1,n)if(bac[i])printf("%d %d\n",i,bac[i]);
	return (0-0);
}
/*
3
2 3
1 1
3 2
3 2 3
3 2 3
*/
/*
3
2 1
1 2
3 3
23 2 23
3 2 3
*/ 