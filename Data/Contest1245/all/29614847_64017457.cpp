//nnnn
//mnn
//nmn
//nnm
//mm
//n 1
//nn 2
//nnn 3
//nnnn 5
//nnnnn 8
//쳲�����
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <cstring>
using namespace std;
const int N=100086;
char s[N];
int n,m;
int T;
int f[N];
const int mod=1000000007;
int main()
{
	f[1]=1;
	f[2]=2;
	for(int i=3;i<=100000;i++)
	{
		f[i]=(f[i-1]+f[i-2])%mod;
	}
	scanf("%s",s);
	for(int i=0;s[i];i++)
	{
		n++;
		if(s[i]=='m'||s[i]=='w')
		{
			printf("0\n");
			return 0;
		}
	}
	long long sum=1;
	int cnt=1;
	s[n]='k';
	for(int i=1;i<=n;i++)
	{
		if(s[i]==s[i-1]&&(s[i]=='n'||s[i]=='u'))
		{
			cnt++;
		}
		else
		{
			if(s[i-1]=='n'||s[i-1]=='u')
			{
				sum*=1ll*f[cnt];
				sum%=mod;
				cnt=1;
			}
		}
	}
	printf("%lld\n",sum%mod);
	return 0;
} 

