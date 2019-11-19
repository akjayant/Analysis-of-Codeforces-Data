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
	ll arr[n];
	ll x=0,y=0;

	f(n)
	{
		cin>>arr[i];
		y+=arr[i];
	}
	sort(arr,arr+n);

	f(n/2)
	{
		x+=arr[i];
		y-=arr[i];
	}

	cout<<(x*x)+(y*y)<<endl;
	return 0;
}