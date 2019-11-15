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
#define ll long long int
#define op std::ios_base::sync_with_stdio(false);cin.tie(NULL)
//using namespace boost::multiprecision;
using namespace std;

int main(int argc, char const *argv[])
{
	op;
	test(t)
	{
		t(a);
		t(b);
		t(c);
		ll ans=0;
		ans+=(min(b,c/2));
		b-=ans;
		ans+=(min(a,b/2));

		ll ans2=0;
		ans2+=min(a,b/2);
		b-=2*ans2;
		ans2+=(min(b,c/2));

		cout<<3*max(ans,ans2)<<endl;
	}
	return 0;
}