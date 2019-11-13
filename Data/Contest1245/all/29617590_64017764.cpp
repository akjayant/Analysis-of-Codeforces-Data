#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<cmath>
#include<iostream>
using namespace std;
#define MOD 1000000007
int n;
char s[100010];
long long ans;
long long f[100010];
bool find1;
int main()
{
	scanf("%s",s);
	n=strlen(s);
	f[0]=1;
	f[1]=1;
	f[2]=2;
	f[3]=3;
	for(int i=4;i<=n;i++)
	{
		f[i]=f[i-1]+f[i-2];
		f[i]%=MOD;
	}
	ans=1;
	for(int i=0;i<n;i++)
	{
		if(s[i]=='m'||s[i]=='w')
		{
			find1=true;
			break;
		}
		if(s[i]=='u')
		{
			int j=i;
			while(s[i+1]=='u')
			{
				i++;
			}
			ans*=f[i-j+1];
			ans%=MOD;
		}
		if(s[i]=='n')
		{
			int j=i;
			while(s[i+1]=='n')
			{
				i++;
			}
			ans*=f[i-j+1];
			ans%=MOD;
		}
	}
	if(find1)
	{
		ans=0;
	}
	cout<<ans<<endl;
	return 0;
} 