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
	scint(n);
	bool tab[n];
	char c;
	int cntr=0;
	for(int i = 0; i < n; i++){
		scanf(" %c", &c);
		if(c == '1'){
			tab[i] = true;
			cntr++;
		}
		else tab[i] = false;
	}
	
	if(cntr == 0){
		print(n);
		prnl;
		return;
	}
	
	if(cntr == 1){
		print(n+1);
		prnl;
		return;
	}
	
	int leftmost, rightmost;
	for(int i = 0;i < n; i++){
		if(tab[i]){
			leftmost = i;
			break;
		}
	}
	
	for(int i = n-1;i >= 0; i--){
		if(tab[i]){
			rightmost = i;
			break;
		}
	}
	
	int out = leftmost+1 + rightmost-leftmost+1 + max(rightmost-leftmost, n-rightmost) + cntr-2;
	int out2 = n-rightmost + rightmost-leftmost+1 + max(rightmost-leftmost, leftmost+1) + cntr-2;
	int out3 = n-leftmost + n-leftmost;
	int out4 = rightmost+1 + rightmost+1;
	print(max(out, max(out2, max(out3, out4))));
	prnl;
}


int main(){
	
	//scint(t);
	//while(t--) TC();
	
	scll(n);
	scll(p);
	scll(w);
	scll(d);
	
	ll peprzezwu = 0;
	if(p % w) peprzezwu = p/w+1;
	else peprzezwu = p/w;
	
	if(n-p/d > n-peprzezwu){
		printf("-1");
		return 0;
	}
	

	
	int prez = 0;
	for(ll z = 0; z < w-d; z++){
		if((w*z)%(w-d) == ((d*n-p)%(w-d)+(w-d))%(w-d)){
			for(ll i = max(n-p/d, 0ll); i < max(n-p/d, 0ll)+(w-d) && i <= n-peprzezwu; i++) if(i%(w-d) == z){
			printf("%lld %lld %lld", (p-d*(n-i))/(w-d), (-p+w*(n-i))/(w-d), i);
			return 0;
			}
		}
	}
	
	printf("-1");
	return 0;
	
	return 0;
}
