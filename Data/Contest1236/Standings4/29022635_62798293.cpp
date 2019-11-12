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
int func(set<int> s1,set<int> s2)
{
	int answer=0;
	for(auto _:s1)
		for(auto __:s2)
			answer+=(__>_);
	return answer;
}
int n;
int32_t main()
{
	desperate_optimization(true);
  	// freopen("input.txt","r",stdin);
  	// return 0;
  	// set<int> st[n];
  	// st[0].insert(1);
  	// st[1].insert(2);
  	// st[2].insert(3);
  	// st[0].insert(4);
  	// st[1].insert(5);
  	// st[2].insert(6);
  	// st[0].insert(7);
  	// st[1].insert(8);
  	// st[2].insert(9);
  	// for(int i=0;i<3;i++)
  	// {
  	// 	for(int j=0;j<3;j++)
  	// 	{
  	// 		cout<<i<<' '<<j<<' '<<func(st[i],st[j])<<'\n';
  	// 	}
  	// }
	cin>>n;
	int resultmat[n][n];
	int value=0;
	int _x=0,_y=0;
	int itr=n*n;
	while(itr--)
	{
		resultmat[_x][_y]=value;
		value++;
		if(_x%2==0) {_y++; if(_y==n) {_y=n-1;_x++;}}
		else {_y--; if(_y==-1) {_y=0; _x++;}}	
	}
	for(int j=0;j<n;j++)
	{
		for(int i=0;i<n;i++) cout<<resultmat[i][j]+1<<' ';
		cout<<'\n';
	}

  	return 0;
}