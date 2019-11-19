#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define allin(a , x) for(auto a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

template<class T1, class T2>
istream &operator>>(istream &in, pair<T1, T2> &P){
	in >> P.first >> P.second;
	return in;
}
template<class T1, class T2>
ostream &operator<<(ostream &out, const pair<T1, T2> &P){
	out << "(" << P.first << ", " << P.second << ")";
	return out;
}
template<class T>
istream &operator>>(istream &in, vector<T> &arr){
	for(auto &x: arr) in >> x;
	return in;
}
template<class T>
ostream &operator<<(ostream &out, const vector<T> &arr){
	for(auto &x: arr) out << x << ' '; cout << "\n";
	return out;
}
template<class T>
istream &operator>>(istream &in, deque<T> &arr){
	for(auto &x: arr) in >> x;
	return in;
}
template<class T>
ostream &operator<<(ostream &out, const deque<T> &arr){
	for(auto &x: arr) out << x << ' '; cout << "\n";
	return out;
}
#define int long long
int g[100005];
int f[100005];
int r[100005];
int dp[100005];
int mod = (int) 1e9 + 7;

ll poww(ll a, ll b)
{
    ll res = 1;
    while (b > 0)
    {
        if(b & 1) res = (res * a)%mod;
        a = (a * a)%mod;
        b >>= 1;
    }
    return res;
}

int32_t main(){
	int n , m ;
	cin>>n>>m;
	g[1] = 2;
	g[2] = 4;
	g[3] = 6; 
	for(int i = 4 ; i <= 100000; i ++){
		g[i] = (2*g[i-1] - g[i-3] + mod)%mod;
	}
	f[1] = 4 , f[2] = 6;
	f[3] = 8;
	for(int i = 4 ; i <=100000 ; i ++){
		f[i] = (2*f[i-1] - f[i-3] +mod) % mod;
	}
	r[1] = 6 , r[2] = 8 , r[3] = 10;
	for(int i = 4 ; i <=100000 ; i ++){
		r[i] = (2*r[i-1] - r[i-3] +mod) % mod;
	}
	dp[1] = g[n] , dp[2] = f[n] , dp[3] = r[n];
	for(int i = 4 ; i <= m ; i ++){
		dp[i] = (2*dp[i-1] - dp[i-3] + mod)%mod;
	}
	cout<< dp[m]%mod << endl;
}