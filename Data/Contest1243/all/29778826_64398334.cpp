#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define ll long long int
#define fill(space,a) memset(space,a,sizeof(space))
#define endl "\n"
#define optimize() ios_base::sync_with_stdio(0);

ll n;

ll gcd(ll a, ll b){
	if (b == 0LL)
		return a;
	return gcd(b, a % b);
}

vector <ll> primes;

int main()
{
	optimize();
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	
	cin >> n;
	if (n % 2 == 0) {
		primes.pb(2LL);
	}
	while (n % 2 == 0){
		n = n / 2LL;
	}

	for (ll i = 3; i <= sqrt(n); i = i + 2){  
		if (n % i == 0) {
			primes.pb(i);
		}
		while (n % i == 0){
			n = n / i;
		}
	}

	if (n > 2LL)
		primes.pb(n);

	if ((int)primes.size() == 1) {
		cout << primes[0] << endl;
	}
	else {
		cout << 1 << endl;
	}

	return 0;
}