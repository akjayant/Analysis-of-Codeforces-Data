#include<bits/stdc++.h>
using namespace std;
int dx[] = { 1,-1,0,0,1,1,-1,-1 };
int dy[] = { 0,0,1,-1,1,-1,1,-1 };
typedef complex<long double> point;
#define sz(a) int((a).size())
#define sc(x) scanf("%d",&x)
#define scl(x) scanf("%lld",&x)
#define MP make_pair
#define ll long long
#define ld long double
#define rep(i,a,b)	for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define vi vector<int>
#define vl vector<ll>
#define ii pair<int,int>
#define LL pair<ll,ll>
#define mem(a,b) memset(a,b,sizeof(a))
#define cross(a,b) ((conj(a)*(b)).imag())
#define pb push_back
const int MAX = 1e9 + 7;
const int mod = 1e9 + 7;
const double pi = 3.14159265358979323846264338327950288419716939937510582097494459;
const double EPS = 1e-10;
const int oo = 1e9 + 7;
const long long OO = 5e18;
ll mulmod(ll a, ll b, ll m)
{
	ll res = 0;
	while (b > 0)
	{
		if (b & 1)  res = ((m - res) > a) ? res + a : res + a - m;
		b >>= 1;
		if (b) a = ((m - a) > a) ? a + a : a + a - m;
	}
	return res;
}
ll power(ll a, ll b, ll m)
{
	if (b == 0) return 1;
	if (b & 1) return mulmod(a, power(a, b - 1, m), m);
	ll tmp = power(a, b / 2, m);
	return mulmod(tmp, tmp, m);
}
bool prime(ll n)
{
	for (int i = 0; i<10; i++)
	{
		ll tmp = (rand() % (n - 1)) + 1;
		if (power(tmp, n - 1, n) != 1)
			return false;
	}
	return true;
}
ll gcd(ll a, ll b) {
	return b == 0 ? a : gcd(b, a % b);
}
int cmp_dbl(double a, double b)		// 0 -> a==b , -1 -> a<b , 1 -> a>b
{
	if (fabs(a - b) <= EPS)	return 0;
	return a < b ? -1 : 1;
}
ll fastpow(ll b, ll e) { if (!e) return 1; if (e & 1) return b * fastpow(b, e - 1); ll x = fastpow(b, e / 2); return x * x; }
ll ExtGCD(ll a, ll b, ll& x, ll& y) { if (!b) { x = 1; y = 0; return a; } ll r = ExtGCD(b, a%b, y, x); y -= a / b*x; return r; }
int Ceil(int x, int y) { return (x + y - 1) / y; }	//ceil(x/y)
int Round(int x, int y) { return (x > 0) ? (x + y / 2) / y : (x - y / 2) / y; }
const int N = 2e5+50; 
const int MOD=1e9+7;
void solve()
{
	int n;	cin>>n;
	string s,t;	cin>>s>>t;
	vi idx;
	rep(i,0,n)
	{
		if(s[i]!=t[i])	idx.push_back(i);
	}
	if(idx.size()!=2)	
	{
	    cout<<"NO"<<endl;
	    return;
	}
	if(s[idx[0]]==s[idx[1]] && t[idx[1]]==t[idx[0]])	cout<<"YES"<<endl;
	else 	cout<<"NO"<<endl;
}
int main()
{
	//freopen("boolean.in", "r", stdin);
	//freopen("boolean.out","w",stdout);
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int t;	cin>>t;
	//t=1;
	while(t--)	solve();
}