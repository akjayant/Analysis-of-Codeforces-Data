#include <stdio.h>
#include <vector>
#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <set>
#include <map>
#define i(x) scanf("%d",&x)
#define l(x) scanf("%lld",&x)
#define rep(a,b,c) for(int a = b;a<c;a++)
#define p pair<long long,long long>
using namespace std;
typedef long long ll;
ll prime(ll x) {
	ll pr=-1;
	for (ll i = 2; i * i <= x; i++) {
		if (x % i == 0) {
			pr = i; break;
		}
	}
	if(pr==-1) return x;
	while (x % pr == 0) {
		x /= pr;
	}
	if (x == 1) return pr;
	else return 1;
}
bool power2(ll x) {
	while (x % 2 == 0) {
		x /= 2;
	}
	return x == 1;
}
int main() {
	ll n; l(n);

	if (n == 1) printf("1");
	else {
		if (n % 2 == 0) {
			if (power2(n)) printf("2");
			else printf("1");
		}
		else {
			printf("%lld", prime(n));
		}
	}

}

