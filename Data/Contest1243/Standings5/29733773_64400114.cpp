#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define vec vector
#define psb push_back
#define ppb pop_back
#define mkp make_pair
#define fst first
#define scd second
#define ins insert
#define psf push_front
#define ppf pop_front
using namespace std;
bool isPrime(ll n) {
    if (n < 2)
		return false;
    if (n < 4)
		return true;
    if (n % 2 == 0 || n % 3 == 0)
		return false;
    for (ll i = 5; i * i <= n; i += 6)
        if (n % i == 0 || n % (i+2) == 0)
           return false;
    return true;
}
map<ll, ll> primeFactoriseMap(ll n) {
	map<ll, ll> a;
	if(n == 1)
		return a;
	ll i, x = 0;
	while((n & 1) == 0) {
		x++;
		n >>= 1;
	}
	if(x) {
		a[2] = x;
		x = 0;
	}
	while(n % 3 == 0) {
		x++;
		n /= 3;
	}
	if(x) {
		a[3] = x;
		x = 0;
	}
	for(i = 5; i * i <= n; i += (2<<(i % 6 == 1))) {
		while(n % i == 0) {
			x++;
			n /= i;
		}
		if(x) {
			a[i] = x;
			x = 0;
		}
	}
	if(n > 1)
		a[n] = 1;
	return a;
}
int main() {
	ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	ll n;
	cin>>n;
	if(n == 1)
		cout << 1;
	else if(!(n&(n-1)))
		cout << 2;
	else if(isPrime(n))
		cout << n;
	else {
		map<ll, ll > a = primeFactoriseMap(n);
		if(a.size()==1)
			cout << a.begin()->fst;
		else
			cout << 1;
	}
	return 0;
}
