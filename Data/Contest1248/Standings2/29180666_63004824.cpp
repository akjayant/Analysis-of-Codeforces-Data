#include <bits/stdc++.h>
#define ff(i,a,b) for(int i=a;i<b;++i)
#define fr(i,a,b) for(int i=a;i>b;--i)
#define FF(i,a,b) for(int i=a;i<=b;++i)
#define FR(i,a,b) for(int i=a;i>=b;--i)
#define rc(t) char t;cin>>t
#define rs(t) string t;cin>>t
#define ri(t) int t;cin>>t
#define rl(t) long t;cin>>t
#define rb(t) bool t;cin>>t
#define rll(t) long long t;cin>>t
#define mp(x,y) make_pair((x),(y))
#define all(a) a.begin(),a.end()
#define pb(a) push_back(a)
#define F first
#define S second
#define IOS ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define set_bits(a) __builtin_popcount(a)
#define inf INT_MAX


using namespace std ;


typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<string> vs;
typedef vector<long long> vll;
typedef vector< vector<int> > vvi;
typedef vector<pair<int, int> > vpii;
typedef vector<pair<long long, int> > vpli;
typedef vector<pair<long long, long long> > vpll;
typedef vector<int>::iterator ii;
typedef vector<vi>::iterator ivi;
typedef unordered_map<int, int> umapii;
typedef unordered_map<int, bool> umapib;
typedef unordered_map<int, string> umapis;
typedef unordered_map<string, int> umapsi;
typedef unordered_map<string, string> umapss;
typedef map<int, int> mapii;
typedef map<string, int> mapsi;
typedef map<int, string> mapis;
typedef map<pair<int, int>, int> mappiii;
typedef map<int, pair<int,int> > mapipii;
typedef map<int, bool> mapib;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef unordered_set<int> useti;
typedef set<int> seti;
typedef priority_queue<int> mxpq;
typedef priority_queue< int, vector<int>, greater<int> > mnpq;


const int maxn = 2e5 + 17, maxv = 1e6 + 17, M = 1e9 + 7;


inline ll mod(ll a,ll b=M){
	a %= b ;
	if(a<0) a += b ;
	return a ;
}

///////////////////////////////////////////////////////////////////////////////




int main(){
	
	IOS ;

	rll(l) ;
	rs(s) ;

	ll lf=0,rt=0 ;
	ff (i,0,l) {
		if (s[i] == '(') lf++ ;
		else rt++ ;
	}

	if (lf != rt) {
		cout << 0 << endl ;
		cout << 1 << " " << 1 << endl ;
		return 0 ;
	}

	ll A = 0 ;
	ll i_ = -1 ;
	ll j_ = -1 ;
	ff (i,0,l) {
		ff (j,i,l) {
			swap (s[i], s[j]) ;
			// cout << i << " " << j << endl ;
			// cout << s << endl ;
			ll c = 0 ;
			ll m = inf ;
			ll ind = -1 ;
			ff (k,0,l) {
				if (s[k] == '(') c++ ;
				else c-- ;
				// cout << c << " " ;
				if (c < m) {
					ind = k ;
					m = c ;
				}
			}
			// cout << endl;
			// cout << m << " " << ind << endl ;
			string s1 = s.substr(0,ind+1) ;
			string s2 = s.substr(ind+1) ;

			string s_ = s2+s1 ;
			// cout << s_ << endl ;
			c = 0 ;
			ll ans = 0 ;
			ff (k,0,l) {
				if (s_[k] == '(') c++ ;
				else c-- ;
				if (c == 0) ans++ ;
			}
			// cout << ans << endl << endl ;

			if (A<ans) {
				A = ans ;
				i_ = i ;
				j_ = j ;
			}

			swap (s[i], s[j]) ;
		}
	}

	cout << A << endl ;
	cout << i_+1 << " " << j_+1 << endl ;
	
}