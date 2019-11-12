#include<bits/stdc++.h>
#include<algorithm>
#include<functional>
//#include<boost/multiprecision/cpp_int.hpp>
#define f(n) for(long long int i=0;i<n;i++)
#define g(n) for(long long int j=0;j<n;j++)
#define ff(a,n) for(long long int i=a;i<n;i++)
#define gg(a,n) for(long long int j=a;j<n;j++)
#define t(a) long long int a;cin>>a
#define test(te) t(te); while(te--)
#define pb push_back
#define mp make_pair
#define mod 1000000007
#define ll long long int
#define op std::ios_base::sync_with_stdio(false);cin.tie(NULL)
//using namespace boost::multiprecision;
using namespace std;

int main(int argc, char const *argv[])
{
	op;
	t(n);
	ll m=2*n;
	std::vector<ll> v[n];
	f(n*n)
	{
		if(i%m >= n)
		{
			v[(2*n-(i%m))-1].pb(i+1);
		}
		else
			v[i%n].pb(i+1);
	}
	
	f(n)
	{
		for(auto j : v[i])
		{
			cout<<j<<" ";
		}
		cout<<endl;
	}
	
	return 0;
}