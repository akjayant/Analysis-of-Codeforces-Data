#include<bits/stdc++.h>
#define LL long long
using namespace std;

const LL p=1e9+7;
LL n,m,ans;

LL quickpow(LL a,LL b,LL p)
{
	if(b==0)return 1;
	LL ans=1,w=a;
	while(b)
	{
		if(b%2)ans=ans*w%p;
		w=w*w%p;
		b/=2;
	}
	return ans;
}

int main()
{
	//cout<<quickpow(3,4,p)<<endl;
	scanf("%I64d%I64d",&n,&m);
	//(2^m-1)^n;
	
	ans=(quickpow(2,m,p)+p-1)%p;
	ans=quickpow(ans,n,p);
	cout<<ans<<endl;
	return 0;
}