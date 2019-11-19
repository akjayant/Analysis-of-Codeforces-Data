#include<bits/stdc++.h>
#define MOD 1000000007
using namespace std;
using ll=long long;

main()
{
	ll n,m;
	cin>>n>>m;
	
	vector<ll> fib(100005);
	fib[0]=1,fib[1]=2;
	
	for(int i=2;i<100005;i++)
	fib[i]=(fib[i-1]+fib[i-2])%MOD;
	
	cout<<(2*(fib[n-1]+fib[m-1]-1))%MOD;
}