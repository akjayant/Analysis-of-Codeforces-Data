#include<bits/stdc++.h>
using namespace std;
using LL=long long;
const int mo=1e9+7;

LL qpow(LL a,LL b)
{
	LL ans=1;
	a%=mo;
	while(b)
	{
		if(b&1)
			ans=ans*a%mo;
		b>>=1;
		a=a*a%mo;
	}
	return ans;
}

const int maxn=1e5+5;
int f[maxn];

void init()
{
	f[0]=1;
	f[1]=1;
	for(int i=2;i<maxn;i++)
		f[i]=(f[i-1]+f[i-2])%mo;
}

char s[maxn];

int main()
{
	init();
	scanf("%s",s);
	int i;
	for(i=0;s[i];i++)
	{
		if(s[i]=='w'||s[i]=='m')
		{
			printf("0\n");
			exit(0);
		}
	}
	int n=i;
	int j;
	LL ans=1;
	for(i=0;i<n;i=j)
	{
		j=i+1;
		if(s[i]=='u'||s[i]=='n')
		{
			while(j<n&&s[j]==s[i])
				j++;
			ans=ans*f[(j-i)]%mo;
		}
	}		
	printf("%lld\n",ans);
	
	return 0;
}