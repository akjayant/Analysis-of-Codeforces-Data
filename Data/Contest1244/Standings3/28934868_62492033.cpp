#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <list>
#include <stack>
#include <queue>
#include <bitset>
#include <numeric>
#include <cassert>
#ifdef DEBUG
#include "./Lib/debug.hpp"
#else
#define dump(...)
template<class T>inline auto d_val(T a, T b) { return a; }
#endif

/* (=＾o＾=) */
#define int ll

/* macro */
#define FOR(i, b, e) for(ll i = (ll)(b); i < (ll)(e); ++i)
#define RFOR(i, b, e) for(ll i = (ll)(e-1); i >= (ll)(b); --i)
#define REP(i, n) FOR(i, 0, n)
#define RREP(i, n) RFOR(i, 0, n)
#define REPC(x,c) for(const auto& x:(c))
#define REPI2(it,b,e) for(auto it = (b); it != (e); ++it)
#define REPI(it,c) REPI2(it, (c).begin(), (c).end())
#define RREPI(it,c) REPI2(it, (c).rbegin(), (c).rend())
#define REPI_ERACE2(it, b, e) for(auto it = (b); it != (e);)
#define REPI_ERACE(it, c) REPI_ERACE2(it, (c).begin(), (c).end())
#define ALL(x) (x).begin(),(x).end()
#define cauto const auto&
/* macro func */
#define SORT(x) do{sort(ALL(x));}while(false)
#define RSORT(x) do{sort((x).rbegin(),(x).rend());}while(false)
#define UNIQUE(v) do{v.erase( unique(v.begin(), v.end()), v.end() );}while(false)
#define MAX(x,y) do{x = std::max(x,y);}while(false)
#define MIN(x,y) do{x = std::min(x,y);}while(false)
#define BR do{cout<<"\n";}while(false)

/* type define */
using ll = long long;
using PAIR = std::pair<ll, ll>;
using VS = std::vector<std::string>;
using VL = std::vector<long long>;
using VVL = std::vector<VL>;
using VVVL = std::vector<VVL>;
using VD = std::vector<double>;
template<class T>
using V = std::vector<T>;

/* using std */
using std::cout;
constexpr char endl = '\n';
using std::cin;
using std::sort;
using std::pair;
using std::string;
using std::stack;
using std::queue;
using std::vector;
using std::list;
using std::map;
using std::unordered_map;
using std::multimap;
using std::unordered_multimap;
using std::set;
using std::unordered_set;
using std::unordered_multiset;
using std::multiset;
using std::bitset;
using std::priority_queue;

/* constant value */
constexpr ll MOD = 1000000007;
//constexpr ll MOD = 998244353;

/* Initial processing  */
struct Preprocessing { Preprocessing() { std::cin.tie(0); std::ios::sync_with_stdio(0); }; }_Preprocessing;

/* Remove the source of the bug */
signed pow(signed, signed) { assert(false); return -1; }

/* define hash */
namespace std { template <>	class hash<std::pair<ll, ll>> { public:	size_t operator()(const std::pair<ll, ll>& x) const { return hash<ll>()(1000000000 * x.first + x.second); } }; }

/* input */
template<class T> std::istream& operator >> (std::istream& is, vector<T>& vec) { for (T& x : vec) is >> x; return is; }

//=============================================================================================

signed main() {
	ll n;
	cin >> n;
	VVL cost; cost.reserve(n);
	REP(_, 3) {
		VL v(n); cin >> v;
		cost.emplace_back(v);
	}

	VL p(n);
	unordered_multimap<ll, ll> graph;
	REP(_, n - 1) {
		ll a, b;
		cin >> a >> b;
		--a; --b;
		graph.emplace(a, b);
		graph.emplace(b, a);
		++p[a]; ++p[b];
	}

	ll fr = 0;
	REP(i, n)if (p[i] == 1) { fr = i; break; }
	REPC(x, p) if(x>2){
		cout << -1 << endl; return 0;
	}

	ll ans = 1e18;

	VL c{0,1,2};
	VL ans_c;
	do {
		ll all = 0;
		V<bool> isUsed(n, false); isUsed[fr] = true;
		queue<PAIR> q;	q.emplace(fr, 0);
		while (!q.empty()) {
			auto from = q.front().first;
			auto it = q.front().second;
			q.pop();

			all += cost[c[it]][from];

			auto range = graph.equal_range(from);
			REPI2(itr, range.first, range.second) {
				auto to = itr->second;
				if (!isUsed[to]) {
					q.emplace(to, (it + 1) % 3);
					isUsed[to] = true;
				}
			}
		}
		if (all < ans) {
			ans = all;
			ans_c = c;
		}
	} while (std::next_permutation(ALL(c)));

	cout << ans << endl;

	VL color(n, -1);
	queue<PAIR> q;	q.emplace(fr, 0);
	while (!q.empty()) {
		auto from = q.front().first;
		auto it = q.front().second;
		q.pop();

		color[from] = ans_c[it];
		auto range = graph.equal_range(from);
		REPI2(itr, range.first, range.second) {
			auto to = itr->second;
			if (color[to] == -1) {
				q.emplace(to, (it + 1) % 3);
			}
		}
	}
	REPC(x, color) {
		cout << x + 1 << " ";
	}BR;
}