#include <bits/stdc++.h>
using namespace std;
const int maxn=100005,K=1000000007;
int n,cnt,ans=1,fac[maxn];
char S[maxn];
int Pow(int A,int B)
{
	int res=1;
	while (B)
	{
		if (B&1) res=(long long)res*A%K;
		A=(long long)A*A%K;
		B>>=1;
	}
	return res;
}
int inv(int A) { return Pow(A,K-2); }
int main()
{
	scanf("%s",S);
	n=strlen(S);
	fac[0]=1;
	for (int i=1;i<=n;i++) fac[i]=(long long)fac[i-1]*i%K;
	for (int i=0;i<n;i++)
		if (S[i]=='m' || S[i]=='w')
		{
			printf("0");
			return 0;
		}
	S[n]='.';
	for (int i=1;i<=n;i++)
		if (S[i]!=S[i-1])
		{
			cnt++;
			if (cnt>1)
			{
				int res=0;
				for (int j=0,k;j<=cnt/2;j++)
				{
					k=cnt-j*2;
					res+=(long long)fac[j+k]*inv(fac[j])%K*inv(fac[k])%K;
					if (res>=K) res-=K;
				}
				ans=(long long)ans*res%K;
			}
			cnt=0;
		} else if (S[i]=='u' || S[i]=='n') cnt++;
	printf("%d",ans);
	return 0;
}
