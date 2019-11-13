#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;
const ull mod = 1000000007;

ll mulmod(ull a, ull b, ull c)
{
	ull x = 0, y = a % c;
	while (b) {
    	if (b & 1) x = (x + y) % c;
    	y = (y << 1) % c;
    	b >>= 1;
	}
	return x % c;
}

int main() {
	ios_base::sync_with_stdio(false); 
    cin.tie(NULL);

	ull fib[100005];
	fib[1] = 1;
	fib[2] = 2;
	fib[3] = 3;
	fib[4] = 5;
	for (int i = 5; i < 100005; ++i)
	{
		fib[i] = (fib[i-1] + fib[i-2]) % mod;
	}

	string input;
	cin >> input;

	ull ans = 1, n = 0, u = 0;
	for (int i = 0; i < input.size(); ++i)
	{
		if(input[i] == 'm' || input[i] == 'w') {
			cout << 0 << endl;
			return 0;
		} else if(input[i] == 'u') {
			u++;
			if(n > 0) ans = mulmod(ans, fib[n], mod);
			n = 0;
		} else if(input[i] == 'n') {
			n++;
			if(u > 0) ans = mulmod(ans, fib[u], mod);
			u = 0;
		} else {
			if(u > 0) ans = mulmod(ans, fib[u], mod);
			if(n > 0) ans = mulmod(ans, fib[n], mod);
			n = 0;
			u = 0;
		}		
	}
	if(u > 0) ans = mulmod(ans, fib[u], mod);
	if(n > 0) ans = mulmod(ans, fib[n], mod);
	n = 0;
	u = 0;
	cout << ans << "\n";
	return 0;
}