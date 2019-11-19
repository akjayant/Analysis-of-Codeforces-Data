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
	test(t)
	{
		
		ll o1=0,e1=0,o2=0,e2=0;

		
		
			t(p);
			ll arr[p];
			f(p){
				cin>>arr[i];
				if(arr[i]%2)
					o1++;
				else
					e1++;
			}
			t(q);
			ll brr[q];
			f(q)
			{
				cin>>brr[i];
				if(brr[i]%2)
					o2++;
				else
					e2++;
			}

		
		cout<<(o2*o1)+(e2*e1)<<"\n";

	}
	return 0;
}