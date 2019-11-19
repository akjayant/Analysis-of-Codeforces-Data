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
void write(LL x)
{
    if(x==0){putchar('0'),putchar('\n');return;}
    int f=0;char ch[20];
    if(x<0)putchar('-'),x=-x;
    while(x)ch[++f]=x%10+'0',x/=10;
    while(f)putchar(ch[f--]);
    putchar('\n');
    return;
}
int n,m,num[2],t;
LL ans;
int main()
{
    //freopen(".in","r",stdin);
    //freopen(".out","w",stdout);
    t=read();
    while(t--)
    {
    	n=read(),ans=num[0]=num[1]=0;
    	rep(i,1,n){int x=read();num[x&1]++;}
		m=read();
		rep(i,1,m){int x=read();ans+=(LL)num[x&1];}
		write(ans);    	
	}
	return 0;
}
/*
3
3
1 3 2
2
0 3

1
1
1
1

1
2
1
1
*/