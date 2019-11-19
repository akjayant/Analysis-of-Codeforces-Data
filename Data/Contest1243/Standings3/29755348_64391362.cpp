#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <bitset>
#include <queue>
#include <stack>
#include <set>
#include <map>

using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<vi> graph;
typedef long long ll;

#define F first
#define S second

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);

    ll n;

    cin >> n;

    if (n == 1) {
    	cout << "1\n";
    	return 0;
    }

    vector<ll> primes;

    if (!(n & 1)) {
        primes.push_back(2);
        while (!(n & 1)) n = (n >> 1);
    }

    for (ll i = 3; i*i <= n; i = i + 2) {
        if (n % i == 0) {
            primes.push_back(i);
            while (n % i == 0) n = n/i;
        }
    }

    if (n > 2) {
        if (primes.size() == 0 || primes[primes.size()-1] != n) {
            primes.push_back(n);
        }
    }

    if (primes.size() > 1) {
    	cout << "1\n";
    } else {
    	cout << primes[0] << '\n';
    }

    return 0;
}
