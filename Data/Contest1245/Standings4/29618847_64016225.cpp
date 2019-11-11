#include<bits/stdc++.h>
using namespace std;
#ifdef DEB
#define D if(1)
#else
#define D if(0)
#endif

using ll = long long;

const int NMAX = 112345;
const int MOD = 1000000007; 
char in[NMAX];
ll fib[NMAX];
ll out=1;
int main()
{
	scanf("%s",in);
	int n = strlen(in);
	fib[0]=fib[1]=1;
	for(int i=0;i<n;i++)
		fib[i+2]=(fib[i+1]+fib[i])%MOD;
	int lenident=0;
	for(int i=0;i<=n;i++)
	{
		if(in[i]=='w' || in[i]=='m') out = 0;
		if(i && in[i]!=in[i-1])
		{
			if(in[i-1]=='u' || in[i-1]=='n')
			{
				out = (out * fib[lenident]) % MOD;
			}
			lenident = 1;
		}
		else
			lenident++;
	}
	printf("%lld\n",out);
	

}

