#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define FASTIO
#define endl "\n"  // Since endl forces a buffer flush which slows down large I/O operations.
#define ff first
#define ss second
#define pb push_back
#define input(c, n) for (int i = 0; i < n; ++i) cin >> c[i];
#define exit_message(s) return 0 * printf(s)
#define show_all(c) for (auto i: c) cout << i << " "; cout << "\n";
#define display(c, a, n) cout << "Displaying array \"" << #c << "\" : \n"; for (int (i) = (a); (i) < (n); ++(i)) cout << (c)[(i)] << " "; cout << "\n";
#define forl(i, a, n) for (int i = (a); (i) < (n); ++(i))
#define dugbe(k) cerr << "-\t> " << #k << " = " << k << "\n";
#define dugbev(arr, idx) cerr << "-\t " << #arr << "[" << idx << "] : " << arr[idx] << "\n";

// What follows is a magical ordered set data structure.
// Supports the following functions:
// find_by_order(int k) - returns k'th smallest element (0-indexed)
// order_of_key(int k) - returns number of elements strictly smaller than k.
using namespace __gnu_pbds;
#define ordered_set tree <ll, null_type, greater_equal <ll>, rb_tree_tag, tree_order_statistics_node_update>
 
/* TIPS FOR DEBUGGING
 * Check if values are not overflowing (use long long where required)
 * Check if ranges are inclusive or not.
 * Check properly if greedy will work or not before using it.
 * Check EDGE CASES!! Seriously, even in 2B, saving 8 points by being
 * 2 minutes faster will bite you in the ass if you don't make sure
 * it works on edge cases.
 * Keep adding to this list.
*/
 
using namespace std;
typedef long long ll;
typedef pair<int, int> pr;
typedef pair<ll, ll> prll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pr> vpr;
ifstream in("input.txt");
const ll mod = 1e9 + 7;
const long double eps = 1e-7;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
long long true_rand(long long n)
{
	// Returns a random number between 0 and n - 1 inclusive using mt19937.
    uniform_int_distribution<long long> uid(0, n - 1);
    return uid(rng);
}
 
ll mod_pow(ll a, ll b, ll mod)
{
	if (b == 0)
		return 1LL;
 
	ll res = mod_pow(a, b >> 1, mod);
	res = (res * res) % mod;
	if (b & 1LL)
		res = (res * a) % mod;
	
	return res;
}
 
const int N = 1e5 + 5;
const ll INF = 1e18;

struct point
{
	int x, y, z, idx;
	point() {}
	point(int a, int b, int c)
	{
		x = a, y = b, z = c;
	}
};


int32_t main()
{
	#ifdef FASTIO
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);
	#endif
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);

	int n;
	cin >> n;
	string s;
	cin >> s;

	int mxb = 0;
	pr opt = {1, 1};
	forl(i, 0, n)
	{
		forl(j, i, n)
		{
			swap(s[i], s[j]);

			int brac = 0;
			int cnt = 0;
			int fail = 0;

			int offset = 0;
			// for (; offset < n; ++offset)
			// {
			// 	if (s[offset] == '(')
			// 		break;
			// }
			int mn = 0;
			forl(k, 0, n)
			{
				if (s[k] == '(')
					++brac;
				else
					--brac;
				if (brac < mn)
				{
					mn = brac;
					offset = k + 1;
				}
			}

			brac = 0, cnt = 0, fail = 0;
			forl(k, 0, n)
			{
				int pos = (k + offset) % n;

				if (s[pos] == '(')
					++brac;
				else
					--brac;
				if (brac == 0)
					++cnt;
				if (brac < 0)
					fail = 1;
			}
			if (brac)
				fail = 1;

			if (!fail && cnt > mxb)
			{
				mxb = cnt;
				opt = {i + 1, j + 1};
			}

			swap(s[i], s[j]);
		}
	}
	cout << mxb << "\n";
	cout << opt.ff << " " << opt.ss << "\n";

	return 0;
}