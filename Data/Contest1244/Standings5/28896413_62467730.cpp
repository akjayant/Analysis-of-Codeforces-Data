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
  int t;
  cin>>t;
  while(t--)
  {
  	int n;
  	string str;
  	cin>>n;
  	cin>>str;
  	int laststair=-1,firststair=n+2;
  	for(int i=0;str[i];i++)
  	{
  		if(str[i]=='1') {laststair=max(laststair,i); firststair=min(firststair,i);}
  	}
  	int answer=n;
  	answer=max(answer,(laststair+1)*2);
  	answer=max(answer,(n-firststair)*2);
  	cout<<answer<<'\n';
  }
  return 0;
}