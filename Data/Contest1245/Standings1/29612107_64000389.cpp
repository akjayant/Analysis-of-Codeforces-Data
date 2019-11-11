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
	char ch[20];int f=0;
	if(!x){putchar('0'),putchar('\n');return;}
	if(x<0)putchar('-'),x=-x;
	while(x)ch[++f]=x%10+'0',x/=10;
	while(f)putchar(ch[f--]);
	putchar('\n');
}
int n,a[3],b[3],c[3];
char s[107],t[107];
int main()
{
	int T=read();
	while(T--)
	{
		n=read();
		rep(i,0,2)a[i]=b[i]=0;
		rep(i,0,2)a[i]=read();
		scanf("%s",s);int num=0;
		rep(i,0,n-1)
		{
			if(s[i]=='R')
			{
				if(a[1])t[i]='P',a[1]--,num++;
				else t[i]='A';
			}
			if(s[i]=='P')
			{
				if(a[2])t[i]='S',a[2]--,num++;
				else t[i]='A';
			}
			if(s[i]=='S')
			{
				if(a[0])t[i]='R',a[0]--,num++;
				else t[i]='A';
			}
		}
		if(num*2>=n)
		{
			puts("YES");
			rep(i,0,n-1)
			{
				if(t[i]!='A')putchar(t[i]);
				else 
				{
					if(a[0])a[0]--,putchar('R');
					else if(a[1])a[1]--,putchar('P');
					else putchar('S');
				}
			}puts("");
		}
		else puts("NO");
	}
	return (0-0);
}