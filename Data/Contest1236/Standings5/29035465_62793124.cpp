#include<iostream>


#define ll long long
using namespace std;

const ll mod = (ll)(1e9+7);

ll Pow(ll x, ll b)
{
	ll ret = 1;
	while(b != 0)
	{
		if(b & 1)
			ret = ret * x % mod;
		x = x * x % mod;
		b >>= 1;
	}
	return ret;
}

ll n, m;


int main()
{
	cin>>n>>m;
	cout<<Pow((Pow(2, m)-1+mod)%mod, n)<<endl;
	return 0;

}
