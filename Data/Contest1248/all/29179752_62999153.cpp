#include<stdio.h>
#include<bits/stdc++.h>
#define f(a,b,c) for(register int a=(b);a<=(c);++a)
#define ff(a,b,c) for(register int a=(b);a>=(c);--a)
#define ll long long
#define int long long
char pbuf[1<<20],*pp1=pbuf;
inline void push(char c){*pp1=c;pp1=(pp1-pbuf==(1<<20)-1)?(fwrite(pbuf,1,1<<20,stdout),pbuf):(pp1+1);}
#define pc push
//#define pc putchar
#define pe pc('\n')
#define ps pc(' ')
#define wer rd()
char *p1,*p2,buf[1<<20];
#define GC (p1==p2&&(p1=buf,p2=buf+fread(buf,1,1<<20,stdin),p1==p2)?0:(*(p1++)))
//#define GC getchar()
using namespace std;
inline ll wer{
	ll ans;char t,k;
	while(((t=GC)!='-')&&(t>'9'||t<'0'));
	k=(t=='-');
	ans=k?0:(t-'0');
	while((t=GC)>='0'&&t<='9')ans=ans*10+t-'0';
	return k?-ans:ans;
}
inline void wt(ll k)
{
	if(k<0)pc('-'),wt(-k);
	else
	{
		if(k<10)pc('0'+k);
		else wt(k/10),pc('0'+k%10);
	}
	return;
}
int f[100001];
#define mod 1000000007
main()
{
	f[1]=2;
	f[2]=4;
	f(i,3,100000)f[i]=(f[i-1]+f[i-2])%mod;
	wt((f[wer]+f[wer]-2+mod)%mod);
	fwrite(pbuf,1,pp1-pbuf,stdout);
    return 0;
}


