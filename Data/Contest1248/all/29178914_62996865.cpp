/*input
100000 100000
*/
#include <bits/stdc++.h>
#define endl "\n"
#define ll long long int
#define vi vector<int>
#define vll vector<ll>
#define vvi vector < vi >
#define pii pair<int,int>
#define pll pair<long long, long long>
#define mod 1000000007
#define inf 1000000000000000001;
#define all(c) c.begin(),c.end()
#define mp(x,y) make_pair(x,y)
#define mem(a,val) memset(a,val,sizeof(a))
#define eb emplace_back
#define f first
#define s second
#define watch(x) cout << (#x) << " is " << (x) << endl
#define N 100002

using namespace std;

long long binpow(long long a, long long b) {
    ll m= mod;
    a %= m;
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

int main()
{
	std::ios::sync_with_stdio(false);
	ll T=1,n,m;string str;
	// cin>>T;
	// cin.ignore(); put after cin, just b4 a getline(cin, s) to avoid getline() directly getting \n
	while(T--)
	{
		ll p=0,q=0,tmp=0,sum=0,count=0; //tmp variable
		int flag=0;
		cin>>n >> m;
		ll a[N];
		a[1]=2;
		a[2]=4;
		for (ll i = 3; i < N; ++i)
		{
			a[i]=(a[i-1]+a[i-2])%mod;
		}
		// cout << a[100000] << endl;
		// ll y = binpow(2,(m+1)/2);
		ll y = a[m];
		ll x = a[n]-2;
		cout << (x+y)%mod << endl;
		
	}
	return 0;
}