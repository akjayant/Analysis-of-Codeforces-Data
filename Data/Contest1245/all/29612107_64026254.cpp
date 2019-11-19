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
#define D double
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
D f[107];
int h[17][17],to[107],px[107],py[107],bac[17][17],cntp;
int main()
{
	dwn(i,10,1)
	{
		if(!(i&1)){rep(j,1,10)cntp++,bac[i][j]=cntp,px[cntp]=i,py[cntp]=j;}
		else {dwn(j,10,1)cntp++,bac[i][j]=cntp,px[cntp]=i,py[cntp]=j;}
	}
	rep(i,1,10)
	{
		rep(j,1,10) 
		{
			h[i][j]=read();int x=i-h[i][j],y=j;
			to[bac[i][j]]=bac[x][y];
		} 
	}/*
	rep(i,1,10)
	{
		rep(j,1,10)cout<<bac[i][j]<<" ";cout<<endl;
	}*/
	f[100]=0;
	dwn(i,99,1)
	{
		D tmp=1.0;int li=min(6,100-i);
		if((100-i)<6)tmp=6.0/(100.0-(D)i),f[i]+=(6.0-(D)li)/6.0;
		rep(j,1,li)
		{
			D x=min(f[i+j],f[to[i+j]]);
			f[i]+=(x+1.0)/6.0;
		}
		f[i]*=tmp;
	}
	printf("%.10lf",f[1]);
	return (0-0);
}