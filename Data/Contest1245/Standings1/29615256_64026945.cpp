#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

#define REP(i,n) for(long long i = 0; i < (n); i++)
#define FOR(i, m, n) for(long long i = (m);i < (n); ++i)
#define ALL(obj) (obj).begin(),(obj).end()
#define SPEED cin.tie(0);ios::sync_with_stdio(false);

template<class T> using V = vector<T>;
template<class T, class U> using P = pair<T, U>;
template<class T> using PQ = priority_queue<T>;
template<class T> using PQR = priority_queue<T,vector<T>,greater<T>>;

constexpr long long MOD = (long long)1e9 + 7;
constexpr long long MOD2 = 998244353;
constexpr long long HIGHINF = (long long)1e18;
constexpr long long LOWINF = (long long)1e15;
constexpr long double PI = 3.1415926535897932384626433;

template <class T> vector<T> make_v(size_t N,T init){return vector<T>(N,init);}
template <class... T> auto make_v(size_t N,T... t){return vector<decltype(make_v(t...))>(N,make_v(t...));}
template <class T> void corner(bool flg, T hoge) {if (flg) {cout << hoge << endl; exit(0);}}
template <class T, class U>ostream &operator<<(ostream &o, const map<T, U>&obj) {o << "{"; for (auto &x : obj) o << " {" << x.first << " : " << x.second << "}" << ","; o << " }"; return o;}
template <class T>ostream &operator<<(ostream &o, const set<T>&obj) {o << "{"; for (auto itr = obj.begin(); itr != obj.end(); ++itr) o << (itr != obj.begin() ? ", " : "") << *itr; o << "}"; return o;}
template <class T>ostream &operator<<(ostream &o, const multiset<T>&obj) {o << "{"; for (auto itr = obj.begin(); itr != obj.end(); ++itr) o << (itr != obj.begin() ? ", " : "") << *itr; o << "}"; return o;}
template <class T>ostream &operator<<(ostream &o, const vector<T>&obj) {o << "{"; for (int i = 0; i < (int)obj.size(); ++i)o << (i > 0 ? ", " : "") << obj[i]; o << "}"; return o;}
template <class T, class U>ostream &operator<<(ostream &o, const pair<T, U>&obj) {o << "{" << obj.first << ", " << obj.second << "}"; return o;}
template <template <class tmp>  class T, class U> ostream &operator<<(ostream &o, const T<U> &obj) {o << "{"; for (auto itr = obj.begin(); itr != obj.end(); ++itr)o << (itr != obj.begin() ? ", " : "") << *itr; o << "}"; return o;}
void print(void) {cout << endl;}
template <class Head> void print(Head&& head) {cout << head;print();}
template <class Head, class... Tail> void print(Head&& head, Tail&&... tail) {cout << head << " ";print(forward<Tail>(tail)...);}
template <class T> void chmax(T& a, const T b){a=max(a,b);}
template <class T> void chmin(T& a, const T b){a=min(a,b);}
void YN(bool flg) {cout << (flg ? "YES" : "NO") << endl;}
void Yn(bool flg) {cout << (flg ? "Yes" : "No") << endl;}
void yn(bool flg) {cout << (flg ? "yes" : "no") << endl;}

int main() {
	int Q; cin >> Q;
	while(Q--){
		ll L,R; cin >> L >> R;
		int N = 30;
		vector<vector<vector<ll>>> dp(N+1,vector<vector<ll>>(8,vector<ll>(4,0)));
		dp[0][0][0] = 1;
		for(int i = 1; i <= N; ++i) {
			ll b = N - i;
			ll l = ((L>>b)&1);
			ll r = ((R>>b)&1);

			//bitdp的な遷移 '=' to '<' の遷移のみを許す。j to k
			for(int j = 0; j < (1<<3); ++j) {			
				for(int k = 0; k < (1<<3); ++k) {
					if((j|k)!=k) continue;
					
					for(int x = 0; x <= 1; ++x) {
						for(int y = 0; y <= 1; ++y) {

							//y-x = x^yより必要
							if((x && y) == 1) continue;

							// = から = への遷移のときは l == x
							if( !((j>>2)&1) && !((k>>2)&1) && l != x) continue;
							// = から < への遷移のときは l <  x
							if( !((j>>2)&1) &&  ((k>>2)&1) && l >= x) continue;
							// < から < への遷移のときは anyone is ok

							// = から = への遷移のときは x == y
							if( !((j>>1)&1) && !((k>>1)&1) && x != y) continue;
							// = から < への遷移のときは x <  y
							if( !((j>>1)&1) &&  ((k>>1)&1) && x >= y) continue;
							// < から < への遷移のときは anyone is ok

							// = から = への遷移のときは y == r
							if( !((j>>0)&1) && !((k>>0)&1) && y != r) continue;
							// = から < への遷移のときは y <  r
							if( !((j>>0)&1) &&  ((k>>0)&1) && y >= r) continue;
							// < から < への遷移のときは anyone is ok
							
							//i-1のx,yは気にせず遷移
							dp[i][k][2*x+y] += accumulate(ALL(dp[i-1][j]),0LL);
						}
					}
				}
			}
		}
		ll ans = 0;
		for(int j = 0; j < 8; ++j) for(int l = 0; l < 4; ++l) ans += dp[N][j][l];
		ans *= 2LL;
		if(L==0||R==0) ans--;
		cout << ans << endl;


	}
    return 0;
}
