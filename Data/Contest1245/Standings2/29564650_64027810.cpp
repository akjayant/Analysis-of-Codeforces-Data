#include<bits/stdc++.h>
using namespace std;
namespace RNG{
    unsigned int seed;
    void init(int p){seed=p;}
    unsigned int rnd()
    {
        unsigned int res=(seed<<4)+(seed^0x23414326)-(seed>>4)-(seed^0x54378320);
        return (seed=((seed+res<<1)^res)>>1);
    }
}
struct ee{
	int f,t,v,l;
}e[15005];
int head[205],cnt;
void add(int a,int b,int c)
{
	e[++cnt]={a,b,c,head[a]};head[a]=cnt;
}
int val[205];
double dp[205];
double dfs(int now)
{
	if(now==100||now==200)return 0;
	if(dp[now]>1e-6)return dp[now];
	double sum=0,res,b=0;
	for(int i=head[now];i;i=e[i].l)
	{
		if(e[i].t==now)b+=1;
		else sum+=(dfs(e[i].t)+1)/6.0;
	}
	if(b<=1e-6)res=sum;
	else res=(b+6*sum)/(6-b);
	if(val[now])res=min(res,dfs(val[now]));
	return dp[now]=res;
}
int id(int x,int y)
{
	if(x&1)return x*10+y+1;
	else return x*10+10-y;
}
int main()
{
	for(int i=9;i+1;--i)
		for(int j=9;j+1;--j)
		{
			int x;
			cin>>x;
			if(x)val[id(i,j)]=id(i+x,j)+100;
			else val[id(i,j)]=0;
		}
	for(int i=0;i<10;++i)
		for(int j=0;j<10;++j)
		{
			int c=id(i,j);
			for(int k=1;k<=6;++k)
			{
				if(c+k<=100)add(c,c+k,1),add(c+100,c+k,1);
				else add(c,c,1),add(c+100,c+100,1);
			}
		}
	/*for(int i=9;i+1;--i,cout<<endl)
		for(int j=9;j+1;--j)cout<<id(i,j)<<" ";
	for(int i=9;i+1;--i,cout<<endl)
		for(int j=9;j+1;--j)cout<<val[id(i,j)]<<" ";*/
	dfs(1);
	cout<<setprecision(10)<<fixed<<dp[1]<<endl;
	return 0;
}
