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

#define MOD 1000000007
long long int fib(long long int n)
{
    if(n < 2)
        return n;
    long long int a = 0,b = 1,ans;
    int i = 1;
    while(i < n)
    {
        ans = (a+b) % MOD;
        a = b;
        b = ans;
        i++;
    }
    return ans;
}

int main(int argc, char const *argv[])
{
	op;
	t(n);
	t(m);
	ll ans=(fib(m+1)+fib(n+1)-1)%MOD;
	cout<<(ans*2)%MOD;
	return 0;
}