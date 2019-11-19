#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstdlib>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cstdio>
#include <iomanip>
 
#define SWS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define pb push_back
#define ppb pop_back
#define ft first
#define sd second
#define read freopen("input.txt", "r", stdin)
#define write freopen("output.txt", "w", stdout)
#define files read; write
 
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;
 
const int Z = (int)3e3 + 228;
const int N = (int)2e5 + 228;
const int INF = (int)1e9 + 228;
const int MOD = (int)1e9 + 7;

int main()
{
	SWS;
	//files;
	ll n;
	cin >> n;
	ll cnt = 0, prime;
	for (ll i = 2; i * i <= n; i++)
		if (n % i == 0)
		{
			cnt++;
			prime = i;
			while (n % i == 0) 
				n /= i;
		}
	if (n != 1)
	{
		cnt++;
		prime = n;
	}
	if (cnt == 1) cout << prime;
	else cout << 1;
	return 0; 
}