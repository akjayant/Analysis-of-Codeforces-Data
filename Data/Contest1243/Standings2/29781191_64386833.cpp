/*#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")
*/
#include<bits/stdc++.h>
using namespace std;
#define testcase(t) int t;cin>>t;while(t--)
#define pb push_back
#define eb emplace_back
#define ll long long int
#define int long long
#define double long double
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define mod 1000000007
#define endl "\n"
#define imax INT_MAX
#define imin INT_MIN
bool sortbysec(const pair<int,int> &a,
              const pair<int,int> &b)
{
    return (a.second < b.second);
}
int nod(int n)
{
	string s = to_string(n);
	return (int)s.length();
}
int32_t main()
{
	IOS
	//n==1
	int n;
	cin>>n;
	int cnt=0;
	int gcd=n;
	for(int i=2;i<=sqrt(n);i++)
	{
		if(n%i==0)
		{
			gcd=__gcd(gcd,i);
			if(i!=n/i)
				gcd=__gcd(gcd,n/i);
		}
	}
	cout<<gcd;
}