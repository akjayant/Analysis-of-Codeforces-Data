//#pragma GCC optimize("O3", "unroll-loops")
//#pragma GCC target("avx2")

#include <bits/stdc++.h>

using namespace std;
/*
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

typedef tree<int,null_type,less<int>,rb_tree_tag,
tree_order_statistics_node_update> ordered_set;

//order_of_key(value)
//find_by_order(idx)

*/

#define DEBUG false
#define dbf if (DEBUG) printf

#define F first
#define S second
#define PB push_back
#define EB emplace_back
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3fLL
#define all(x) x.begin(),x.end()
#define sz(x) int(x.size())
#define endl '\n'
#define mdc(a, b) (__gcd((a), (b)))
#define mmc(a, b) (( (a)/__gcd((a), (b)) )*(b))

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll, ll> pll;

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

const double EPS = 1e-9;
const double PI = acos(-1);

const int MOD = 1000000007;
int n;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	int t;
	cin >> t;
	while(t--){
		ll n1, n2;
		cin >> n1;
		
		ll a=0, b=0;
		for(int i=0; i<n1; i++){
			int x;
			cin >> x;
			if(x%2 == 0)
				a++;
		}
		cin >> n2;
		for(int i=0; i<n2; i++){
			int x;
			cin >> x;
			if(x%2 == 0)
				b++;
		}
		cout << a*b + (n1-a)*(n2-b) << endl;
	}

	return 0;
}
