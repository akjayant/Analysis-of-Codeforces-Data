#include <iostream> 
#include <list> 
#include <limits.h> 
#include <sstream>
#include <vector>
#include <map>
#include <stack>
#include <vector>
#include <set>
#include <queue>
#include <algorithm>
#include <math.h>
#include <unordered_map>
#include <unordered_set>

#define ll long long

using namespace std;

bool isPrime(ll n) { 
    // Corner case 
	if (n <= 1) 
		return false; 

    // Check from 2 to n-1 
	for (ll i = 2; i * i <= n; i++) {
		if (n % i == 0) {
			return false; 
		}
	}

	return true; 
} 

bool isPow(ll i, ll n) {
	ll m=n;
	while (m>1) {
		if (m%i != 0) break;
		m/=i;
	}
	return (m == 1);
}

int main() {
	// freopen("in.txt", "r", stdin);	
	ll n;
	cin >> n;
	if (isPrime(n)) {
		cout << n << endl;
	} else {
		for (ll i = 2; i * i <= n; i++) {
			if (isPrime(i) && isPow(i, n)) {
				cout << i << endl;
				return 0;
			}
		}
		cout << 1 << endl;
	}
	return 0;
}









