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
#define maxn 300007
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
int n,cnt0,maxx,maxi=1,maxj=1,tp,stk[maxn];
char s[maxn],t[maxn];
int work()
{
	tp=0;int pos=0;
	rep(i,1,n)
	{
		if(s[i]=='(')stk[++tp]=i;
		else
		{
			if(!tp)pos=i;
			else tp--;
		}
	}
	if(pos)
	{
		int cut=pos+1;
		int cntt=0;
		rep(i,cut,n)t[++cntt]=s[i];
		rep(i,1,cut-1)t[++cntt]=s[i];//cout<<" cut:"<<cut<<endl;
	}
	else 
	{
		rep(i,1,n)t[i]=s[i];
	}
	tp=0;int res=0;
	//cout<<s+1<<" "<<t+1<<" "<<strlen(t+1)<<endl;
	rep(i,1,n)
	{
		if(tp==0)res++;
		if(t[i]=='(')tp++;
		else tp--;
	}
	return res;
}
int main()
{
    //freopen(".in","r",stdin);
    //freopen(".out","w",stdout);
    scanf("%d%s",&n,s+1);
    if(n&1){puts("0"),puts("1 1");return 0;}
    rep(i,1,n)if(s[i]=='(')cnt0++;
    if(cnt0!=n/2){puts("0"),puts("1 1");return 0;}
    rep(i,1,n)rep(j,1,i)
    {
    	swap(s[i],s[j]);
    	int tmp=work();
    	swap(s[i],s[j]);
    	if(tmp>maxx)maxx=tmp,maxi=i,maxj=j;
    }
    printf("%d\n%d %d",maxx,maxi,maxj);
	return 0;
}