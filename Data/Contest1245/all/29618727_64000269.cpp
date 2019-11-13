#include<bits/stdc++.h>
typedef long long ll;
ll mod =1000000007;
using namespace std;
int n;

ll powmod(ll a,ll b) {ll res=1;a%=mod;for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}

int main()
{
	int i,j,fl,test,a,b;
	scanf("%d",&test);
	while(test--)
	{
		scanf("%d%d",&a,&b);
		if(__gcd(a,b)!=1)
			printf("Infinite\n");
		else
			printf("Finite\n");
	}

	return 0;
}