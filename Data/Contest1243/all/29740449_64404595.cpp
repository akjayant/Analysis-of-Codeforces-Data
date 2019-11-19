/*input
99999999999
*/
#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"
#define ll long long int
#define vi vector<int>
#define vll vector<ll>
#define vvi vector < vi >
#define pii pair<int,int>
#define pll pair<long long, long long>
#define mod 1000000007
#define inf 1000000000000000001
#define all(c) c.begin(),c.end()
#define mp(x,y) make_pair(x,y)
#define mem(a,val) memset(a,val,sizeof(a))
#define eb emplace_back
#define f first
#define s second
#define watch(x) cout << (#x) << " is " << (x) << endl
#define N 100002

using namespace std;

ll fac;

bool is_prime(ll n) {
    // Assumes that n is a positive natural number
    // We know 1 is not a prime number
    if (n == 1) {
        return false;
    }

    ll i = 2;
    // This will loop from 2 to int(sqrt(x))
    while (i*i <= n) {
        // Check if i divides x without leaving a remainder
        if (n % i == 0) {
        	fac=i;
            // This means that n has a factor in between 2 and sqrt(n)
            // So it is not a prime number
            return false;
        }
        i++;
    }
    // If we did not find any factor in the above loop,
    // then n is a prime number
    return true;
}

int main()
{
	fastio
	ll T=1,n,m;string str;
	// cin>>T;
	// cin.ignore(); put after cin, just b4 a getline(cin, s) to avoid getline() directly getting \n
	while(T--)
	{
		ll p=0,q=0,tmp=0,sum=0,count=0; //tmp variable
		int flag=0;
		
		cin>>n;
		tmp =n;
		if(n==1)
		{
			cout << 1 << endl;
			return 0;
		}
		while(n%2==0)
		{
			n/=2;
			flag=1;
		}
		if(n==1)
		{
			cout << 2 << endl;
			return 0;
		}
		else if(flag==1)
		{
			cout << 1 << endl;
			return 0;
		}
		if(is_prime(n)==true)
		{
			cout << n << endl;
			return 0;
		}
		
		if(is_prime(fac)==true)
		{
			while(n%fac==0)
			{
				n/=fac;
			}
			if(n==1)
			{
				cout << fac << endl;
				return 0;
			}
		}
		cout << 1 << endl;
		
	}
	return 0;
}