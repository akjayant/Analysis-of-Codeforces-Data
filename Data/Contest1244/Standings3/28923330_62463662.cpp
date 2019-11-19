#include <cstdio>
//#include <iostream>
#include <vector>
#include <deque>
#include <set>
#include <map>
#include <algorithm>
#include <utility>
#include <random>
 
#define turbo ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define scint(x) int x; scanf("%d", &x)
#define scll(x) ll x; scanf("%lld", &x)
#define print(x) printf("%d", x)
#define prll(x) printf("%lld", x)
#define prsp printf(" ")
#define prnl printf("\n")
#define ST first
#define ND second
#define PB push_back
 
using namespace std;
typedef long long int ll;
typedef pair< int, int > pii;
typedef pair< ll, ll > pll;
typedef pair< int, pii > tii;
typedef vector< int > vi;
typedef vector< ll > vll;
typedef vector< vi > vvi;
typedef vector< pii > vpii;
typedef vector< pll > vpll;
typedef vector< tii > vtii;
typedef deque< int > di;
typedef deque< ll > dll;
typedef deque< di > ddi;
typedef deque< pii > dpii;
typedef set< int > si;
typedef set< ll > sll;
typedef set< pii > spii;
typedef multiset< int > msi;
typedef multiset< ll > msll;
typedef multiset< pii > mspii;
 
const ll MOD = 998244353;
const int INF = 1000000100;
const ll INFll = 1000000000001000000;
 
namespace B{
	ll gcd(ll a, ll b){
		return b ? gcd(b, a%b) : a;
	}
	
	bool prime(ll p){
		for(ll i = 2; i*i <= p; i++){
			if(p%i == 0) return false;
		}
		return true;
	}
	
	ll pow(ll b, ll e, ll mod){
		if(!e) return 1;
		if(e%2) return (b*pow(b, e-1, mod))%mod;
		return pow((b*b)%mod, e/2, mod);
	}
	
	ll revmod(ll a, ll p){
		return pow(a, p-2, p);
	}
	
	ll fact(ll n, ll mod){
		if(n >= mod) return 0;
		ll out = 1;
		for(ll i; i <= n; i++){
			out *= i;
			out %= mod;
		}
		return out;
	}
}

void TC(){
	scint(a);
	scint(b);
	scint(c);
	scint(d);
	scint(k);
	
	for(int i = 0; i <= k; i++){
		if(i*c >= a && (k-i)*d >= b){
			printf("%d %d", i, k-i);
			prnl;
			return;
		}
	}
	
	printf("-1\n");
	return;
}

int main(){
	
	scint(t);
	while(t--) TC();
	
	return 0;
}
