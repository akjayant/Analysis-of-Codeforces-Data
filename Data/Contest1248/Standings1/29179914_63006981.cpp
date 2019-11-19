#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#ifdef DEB
#define D if(1)
#else
#define D if(0)
#endif

const int NMAX = 1123456;
const int MOD = 1000000007;

int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	ll out=2;
	{
		ll stejna=0;
		ll ruzna=1;
		for(int i=1;i<n;i++)
		{
			int old_stejna=stejna;
			int old_ruzna = ruzna;
			ruzna=(old_stejna+old_ruzna)%MOD;
			stejna=(old_ruzna)%MOD;
		}
		out += (stejna+ruzna-1)*2;
		D printf("+= %lld",(stejna+ruzna-1)*2);
	}
	{
		ll stejna=0;
		ll ruzna=1;
		for(int i=1;i<m;i++)
		{
			int old_stejna=stejna;
			int old_ruzna = ruzna;
			ruzna=(old_stejna+old_ruzna)%MOD;
			stejna=(old_ruzna)%MOD;
		}
		out += (stejna+ruzna-1)*2;
		D printf("+= %lld\n",(stejna+ruzna-1)*2);
	}
	printf("%lld\n",out%MOD);
	return 0;
}
