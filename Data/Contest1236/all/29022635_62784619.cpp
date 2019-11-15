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
int32_t main()
{
	desperate_optimization(true);
  	// freopen("input.txt","r",stdin);
  	int a,b,c;
  	int t;
  	cin>>t;
  	while(t--)
  	{
  		cin>>a>>b>>c;
  		int answer=min(b,c/2);
  		b-=answer;
  		answer+=min(a,b/2);
  		cout<<3*answer<<'\n';
  	}
  	

  	return 0;
}