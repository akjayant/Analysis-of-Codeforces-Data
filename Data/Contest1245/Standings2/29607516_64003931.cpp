#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define mod 1000000007
#define N 100010
char str[N]; int f[N],n;
int main()
{
	scanf("%s",str+1),n=strlen(str+1),f[0]=1;
	for(int i=1;i<=n;i++) if(str[i]=='m'||str[i]=='w') printf("0\n"),exit(0);
	for(int i=1;i<=n;i++)
		if(str[i]==str[i-1]&&str[i]=='u') f[i]=(f[i-1]+f[i-2])%mod;
		else if(str[i]==str[i-1]&&str[i]=='n') f[i]=(f[i-1]+f[i-2])%mod;
		else f[i]=f[i-1];
	printf("%d\n",f[n]);
}