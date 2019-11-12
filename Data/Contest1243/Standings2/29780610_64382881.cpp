#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <deque>
#include <numeric>
#include <bitset>
#define debug(x)  cerr << #x << " = " << x << endl
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair <ll, ll> pll;
typedef pair <int, int> pii;

const int maxN = 1e4 + 5;
const ll INF = 1e18;
const ll MOD = 1e9 + 7;

ll gcd(ll a, ll b) {return !b ? a : gcd(b, a % b);}
ll sq(ll x) {return (x * x) % MOD;}
ll modP(ll a, ll b) {return (!b ? 1 : (sq(modP(a, b / 2)) * (b % 2 ? a : 1)) % MOD);}

vector <int> vec;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int Q; cin >> Q;
	while (Q--){
		int n; cin >> n;
		string s, t; cin >> s >> t;
		vec.clear();
		for (int i = 0; i < n; i++) if (s[i] != t[i]) vec.push_back(i);
		if (vec.size() != 2){
			cout << "No\n";
			continue;
		}
		if (s[vec[0]] == s[vec[1]] && t[vec[1]] == t[vec[0]]) cout << "Yes\n";
		else cout << "No\n";
	}
	return 0;
}
 

