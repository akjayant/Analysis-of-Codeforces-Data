#include <set>
#include <map>
#include <queue>
#include <deque>
#include <cmath>
#include <vector>
#include <cstdio>
#include <cstring>
#include <iomanip>
#include <cassert>
#include <iostream>
#include <algorithm>
#define X first
#define Y second
#define pi 3.14159265358979323846
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<ll, int> pli;
typedef pair<int, ll> pil;
 
const int o = 1 << 17;
 
const int mod = 1000000007;
 
const int inf = 0x3f3f3f3f;
const ll huge = 100000000000000000LL;
 
typedef long long ll;
typedef pair<ll, int> pli;
typedef pair<int, int> pii;
typedef pair<pli, int> st;
typedef priority_queue<st> pq;

const int maxn = 100005;

int n;
string s;

int dp[maxn];
 
int main() {
    ios::sync_with_stdio(false);
	cin >> s;
	n = (int)s.size();
	for (int i = 0; i < n; i++)
		if (s[i] == 'm' || s[i] == 'w') {
			cout << 0 << endl;		
			return 0;		
		}
	dp[0] = 1;
	dp[1] = 1;
	if (s[0] == s[1] && (s[0] == 'u' || s[0] == 'n'))
		dp[1]++;
	for (int i = 2; i < n; i++) {
		if (s[i] == s[i - 1] && (s[i] == 'u' || s[i] == 'n'))
			dp[i] = (dp[i - 2] + dp[i - 1]) % mod;
		else
			dp[i] = dp[i - 1];
	}
	cout << dp[n - 1] << endl;
    return 0;
}
