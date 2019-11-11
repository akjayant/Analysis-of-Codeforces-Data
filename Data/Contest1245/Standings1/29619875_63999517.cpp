#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1000000007;
int f[100001];
signed main()
{
	f[0]=f[1]=1;
	for(int i=1;i<=100000;i++)
		f[i]=(f[i-1]+f[i-2])%mod;
	string s;
	cin>>s;
	int n=s.size();
	for(int i=0;i<n;i++)
		if(s[i]=='m'||s[i]=='w')
		{
			printf("0\n");
			return 0;
		}
	int ans=1;
	for(int i=0;i<n;i++)
		if(s[i]=='n'||s[i]=='u')
		{
			int tmp=i;
			while(i<n&&s[i]==s[tmp])
				i++;
			ans=ans*f[i-tmp]%mod;
			i--;
		}
	printf("%lld\n",ans);
	return 0;
}