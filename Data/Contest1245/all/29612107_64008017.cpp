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
#define maxn 100007
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
const LL mod=1e9+7;
int mo(int x){return x>=mod?x-mod:x;}
char s[maxn];
int n,f[maxn][2];
int main()
{
	scanf("%s",s+1);n=strlen(s+1);
	int no=0;
	rep(i,1,n)if(s[i]=='w'||s[i]=='m'){no=1;break;}
	if(no){puts("0");return 0;} 
	f[1][0]=f[2][1]=f[2][0]=1;
	rep(i,3,n){f[i][0]=mo(f[i-1][0]+f[i-1][1]),f[i][1]=mo(f[i-2][0]+f[i-2][1]);}
	int ans=1,now=0;
	rep(i,1,n)
	{
		if(i==1||s[i]!=s[i-1]||(s[i]!='n'&&s[i]!='u'))
		{
			//out<<i<<" "<<now<<endl;
			if(now)ans=(LL)ans*mo(f[now][0]+f[now][1])%mod;
			now=0;
		}
		if(s[i]=='n'||s[i]=='u')now++; 
	}
	if(now)ans=(LL)ans*mo(f[now][0]+f[now][1])%mod;
	write(ans);
	return (0-0);
}