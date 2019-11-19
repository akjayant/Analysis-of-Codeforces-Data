#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
//typedef __int128 LL;
//typedef unsigned long long ull;
//#define F first
//#define S second
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<ld,ld> pdd;
const ld PI=acos(-1);
const ld eps=1e-9;
//unordered_map<int,int>mp;
#define ls (o<<1)
#define rs (o<<1|1)
#define pb push_back
const int seed=131;
const int M = 1e5+7;
int a[M];
int main()
{
	ios::sync_with_stdio(false);
  	cin.tie(0);
  	int n;
  	cin>>n;
  	for(int i=1;i<=n;i++)
  	{
  		cin>>a[i];
	  }
	sort(a+1,a+1+n);
	int z=n/2;
	ll x=0,y=0;
	for(int i=1;i<=z;i++)
	x+=a[i];
	for(int i=z+1;i<=n;i++)
	y+=a[i];
	cout<<x*x+y*y<<endl;
	return 0;
}