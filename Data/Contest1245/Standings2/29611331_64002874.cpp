/*
Author : Puneet Rai
Team : BlundersPride
Date : 01-11-2019
Time : 20:19:53
*/


#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define vll vector<ll>
#define vvll vector< vll >
#define vld vector< ld >
#define vvld vector< vld >
#define pll pair<ll ,ll >
#define vpll vector< pll >
#define mp make_pair
#define pb push_back
#define MOD 1000000007
#define endl "\n"
#define flash ios_base::sync_with_stdio(false);cin.tie(NULL);
#define test ll t;read(t);while(t--)
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define fst first
#define scd second

#define forn(i,n) for(ll (i) = 0 ; (i) < (n) ; ++(i))
#define for1(i,n) for(ll (i) = 1 ; (i) <= (n) ; ++(i))
#define forr(i,n) for(ll (i) = (n)-1 ; (i)>=0 ; --(i))
#define forab(i,a,b,c) for(ll (i) = a ; (i) <= (b) ; (i)+=(c))

using namespace std;

////////////////////////////////////////////////////////////////// Inputs ////////////////////////////////////////////////////////////////////////////////////
template <typename T>
void read(T &x){
	cin >> x;
}

template <typename T , typename T0>
void read(T &x,T0 &y){
	cin >> x >> y;
}

template <typename T , typename T0 , typename T1>
void read(T &x,T0 &y,T1 &z){
	cin >> x >> y >> z;
}

template <typename T , typename T0 , typename T1 , typename T2>
void read(T &x,T0 &y,T1 &z,T2 &w){
	cin >> x >> y >> z >> w;
}

template <typename T , typename T0>
void read(pair< T , T0 > &p){
	cin >> p.fst >>p.scd;
}

template <typename T>
void read(vector< T > &oneD){
	for(ll i=0;i<oneD.size();i++){
		read(oneD[i]);
	}
}

template <typename T>
void read(T oneD[] , int n){
	for(ll i=0;i<n;i++){
		read(oneD[i]);
	}
}

/////////////////////////////////////////////////////////////////////////// Outputs ////////////////////////////////////////////////////////////////////////////

template <typename T>
void write(T &x){
	
	cout << x << " ";
}

template <typename T , typename T0>
void write(T &x,T0 &y){
	cout << x << " " << y << "\n";
}

template <typename T , typename T0 , typename T1>
void write(T &x,T0 &y,T1 &z){
	cout << x << " " << y << " " << z << "\n";
}

template <typename T , typename T0 , typename T1 , typename T2>
void write(T &x,T0 &y,T1 &z,T2 &w){
	cout << x << " " << y << " " << z << " " << w << "\n";
}

template <typename T , typename T0>
void write(pair< T , T0 > &p){
	write(p.fst);
	write(p.scd);
	cout << endl;
}

template <typename T>
void write(vector< T > &oneD){
	for(ll i=0;i<oneD.size();i++){
		write(oneD[i]);
	}
	cout << endl;
}

template <typename T>
void write(T oneD[] ,int n){
	for(ll i=0;i<n;i++){
		write(oneD[i]);
	}
	cout << endl;
}

template <typename T , typename T0>
void write(map< T , T0 > &mpp){
	for(auto it : mpp){
		write(it.fst);
		cout << ": ";
		write(it.scd);
		cout << "\n";
	}
	cout<<endl;
}

///////////////////////////////////////////////////////////////////////// Maths //////////////////////////////////////////////////////////////////////////////

vll sieve;
void Sieve(int N){
	const ll maxn = N;
	sieve.resize(maxn);
	forn(i,maxn) sieve[i] = i;
	sieve[1] = -1;
	sieve[0] = -1;
	forab(i,2,maxn,1) if(i == sieve[i]) for(ll j = 2*i ; j < maxn ; j+=i) if(sieve[j] == j) sieve[j] = i;
}


ll extended_GCD(ll a , ll b , ll &x , ll &y){
	if(a == 0){
		x = 0;
		y = 1;
		return b;
	}
	ll x1 , y1;
	ll gcd = extended_GCD(b%a , a , x1 , y1);
	x = y1 - (b/a)*x1; 
	y = x1;
	return gcd;
}

ll power(ll a, ll b, ll m = MOD) {
    a %= m;
    ll res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

ll modinv(ll a , ll mod = MOD){
	ll x , y;
	extended_GCD(a , mod , x , y);
	if(x < 0) x += mod;
	return x;
}


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
const int N = 1e5+1;

int dp[N];
string s;

int rec(int i) {
	int n = s.size();
	if(i == n) {
		return 1;
	}
	if(dp[i] != -1) {
		return dp[i];
	}
	int a = rec(i + 1);
	int b = 0;
	if((i+1) < n && s[i] == 'n' && s[i+1] == 'n') {
		b = rec(i + 2);
	}
	if((i+1) < n && s[i] == 'u' && s[i+1] == 'u') {
		b = rec(i + 2);
	}
	dp[i] = a + b;
	if(dp[i] > MOD) {
		dp[i] -= MOD;
	}
	return dp[i];
}

void solve(){
	cin >> s;
	for(auto c: s) {
		if(c == 'm' || c == 'w') {
			cout << 0 << endl;
			return;
		}
	}
	memset(dp , -1 , sizeof dp);
	cout << rec(0) << "\n";	
}

int main()
{	
	flash
	solve();
    return 0;
}
