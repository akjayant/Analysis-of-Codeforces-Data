/*
 *  AUTHOR : MANAV PATEl
*/
#include<bits/stdc++.h>
#include<functional>
//#include<boost/multiprecision/cpp_int.hpp>
//using namespace boost::multiprecision;
using namespace std;

namespace fastio
{

	template <class T> istream &operator>>(istream &os, vector<T> & vec){for (auto &u : vec)os >> u;return os;}
    template <class T> ostream &operator<<(ostream &os, const vector<T> & vec){for (auto &u : vec)os << u << " ";return os;}
    template<class T1, class T2> inline istream& operator>>(istream& os, pair<T1, T2>& p) { return os >> p.first >> p.second; }
    template<class T1, class T2> ostream& operator<<(ostream& os, const pair<T1, T2>& p) { return os << p.first << " " << p.second; }
    template <class T> ostream &operator<<(ostream &os, set<T> & con) { for (auto &u : con) os << u << " "; return os; }
	void re() {}
	template <typename T, typename... args> void re(T& x, args&... tail)
	{
		cin >> x;
		re(tail...);
	}
	void pr() {}
	template <typename T> void pr(const T& x)
	{
		cout << x;
	}
	template <typename T, typename... args> void pr(const T& x, const args&... tail)
	{
		cout << x << " ";
		pr(tail...);
	}
	template <typename... args> void prln(const args&... tail)
	{
		pr(tail...);
		cout << "\n";
	}
}
using namespace fastio;

typedef long long int ll;
typedef long double ld;

const ll mod = 1e9+7;
const ll mod1 = 998244353;

#define fill(a)  memset(a, 0, sizeof(a))
#define fst first
#define snd second
#define mp make_pair
#define pb push_back

void fs(ll &number)
{
	bool negative = false;
	register int c;
	number = 0;
	c = getchar();
	if (c=='-')
	{
		negative = true;
		c = getchar();
	}
	for (; (c>47 && c<58); c=getchar())
		number = number *10 + c - 48;
	if (negative)
		number *= -1;
}

bool isprime(ll n)
{
    if (n <= 1)  return false;
    if (n <= 3)  return true;
    if (n%2 == 0 || n%3 == 0) return false;

    for (ll i=5; i*i<=n; i=i+6)
        if (n%i == 0 || n%(i+2) == 0)
           return false;

    return true;
}

bool checkisTree(ll degree[],ll n)
{
    ll deg_sum = 0;
    for (ll i = 0; i < n; i++)
        deg_sum += degree[i];
    return (2*(n-1) == deg_sum);
}

ll gcd(ll a, ll b)
{

    if (b == 0)  return a;
    return gcd(b, a % b);

}

ll findS(ll s)
{
    return (sqrt(8*s + 1) - 1)/2;
}

ll LOGN(ll n , ll r)
{
	return (n > r-1) ? (1 + LOGN(n / r , r)) : 0 ;
}

int main()
{
	cin.sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	cin.tie(0);
	ll t=1;
	re(t);
	while(t--)
	{
		ll n, m;
		re(n);
		ll arr[n];
		for(ll i=0; i<n; i++)
		{
			re(arr[i]);
		}
		re(m);
		ll arr1[m];
		for(ll i=0; i<m; i++)
		{
			re(arr1[i]);
		}
		ll p1 = 0, p2 = 0, q1 = 0, q2 = 0;
		for (ll i = 0; i < n; i++)
		{
			if (arr[i] % 2 == 1) p1++;
			else p2++;
		}
		for (ll i = 0; i < m; i++)
		{
			if (arr1[i] % 2 == 1) q1++;
			else q2++;
		}
 
		cout << p2*q2 + p1*q1  << "\n";
	}
}

