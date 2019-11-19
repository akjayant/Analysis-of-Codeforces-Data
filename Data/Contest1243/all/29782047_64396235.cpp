#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <utility>
#include <cmath>
#include <set>
#include <fstream>
typedef long long ll;

using namespace std;




ll MOD = 1e9 + 7;

vector<ll> divisors;

void f(ll n) {
	for (ll i = 2; i * i <= n; i++) {
		if (n % i == 0) {
			divisors.push_back(i);
			if(i!=n/i)
			divisors.push_back(n/i);
		}
	}
	
}

int main()
{
	
	ll n;
	cin >> n;
	f(n);
	
	if (divisors.size() == 0) {
		cout << n << endl;
		return 0;
	}
	
	sort(divisors.begin(), divisors.end());
	
	for (int i = 1; i < divisors.size(); i++) {
		if (divisors[i] % divisors[0] != 0) {
			cout << 1 << endl;
			return 0;
		}
	}
	cout << divisors[0] << endl;

}


