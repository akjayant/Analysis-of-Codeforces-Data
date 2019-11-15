#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<queue>
#include<ctime>
#define int long long
#define lowbit(x) x&-x
#define inf 2147483647
#define N 200005
#define mod 1000000007
using namespace std;
char ch[100005];
int f[100005];

signed main()
{
	//freopen("x.in","r",stdin);
	//freopen("x.out","w",stdout);
	cin>>ch;
	int i=0;
	int len=strlen(ch);
	int ans=1;
	f[0]=1;
	f[1]=1;
	for(int i=2;i<=100000;i++)
	    f[i]=(f[i-1]+f[i-2])%mod;
	while(i<len)
	{
		if(ch[i]=='m'||ch[i]=='w')
		{
			cout<<"0";
			return 0; 
		}
		else if(ch[i]=='n')
		{
		    int num=0;
			while(ch[i]=='n')
			    num++,i++;
			ans=(ans*f[num])%mod;
		}
		else if(ch[i]=='u')
		{
			int num=0;
			while(ch[i]=='u')
			    num++,i++;
			ans=(ans*f[num])%mod;
		}
		else
		    i++;
	}
    cout<<ans<<endl;
	return 0;
}
