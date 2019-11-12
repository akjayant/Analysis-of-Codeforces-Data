#pragma GCC optimize("Ofast")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <bits/stdc++.h>
#define int long long int
using namespace std;

// Kyu? Chonk gaye!? 😮

void desperate_optimization(bool submitting=true,int precision=10)
{
  if(!submitting) return;
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cout.setf(ios::fixed);
  cout.setf(ios::showpoint);
  cout.precision(precision);
}
int mod=1e9+7;
int fastexp(int base,int exp)
{
	int answer=1;
	while(exp)
	{
		if(exp&1) {answer*=base; answer%=mod;}
		base*=base;
		exp/=2;
		base%=mod;
	}
	return answer;
}
int32_t main()
{
	desperate_optimization(true);
  	// freopen("input.txt","r",stdin);
  	int n,m;
  	cin>>n>>m;
  	int answer=fastexp(2,m)-1+mod;
  	answer%=mod;
  	answer=fastexp(answer,n);
  	cout<<answer;

  	return 0;
}