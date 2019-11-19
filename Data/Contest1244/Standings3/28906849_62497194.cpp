#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define trace1(x)                cout<<#x<<": "<<x<<endl;
#define trace2(x, y)             cout<<#x<<": "<<x<<" | "<<#y<<": "<<y<<endl;
#define trace3(x, y, z)          cout<<#x<<":" <<x<<" | "<<#y<<": "<<y<<" | "<<#z<<": "<<z<<endl;
#define trace4(a, b, c, d)       cout<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<endl;
#define trace5(a, b, c, d, e)    cout<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<" | "<<#e<< ": "<<e<<endl;
#define trace6(a, b, c, d, e, f) cout<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<" | "<<#e<< ": "<<e<<" | "<<#f<<": "<<f<<endl;
#define fio ios_base::sync_with_stdio(false);cin.tie(NULL);

typedef long long int lli;
typedef lli ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<lli, lli> plli;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<pair<int, int> > vpii;
typedef vector<pair<lli, lli> > vplli;
typedef vector<lli> vlli;
typedef vector<vlli> vvlli;
typedef vector<char> vc;
typedef vector<vc> vvc;
typedef vector<bool> vb;
typedef vector<vb> vvb;

#define PI 3.141592653589793
#define mod (lli)(1000*1000*1000+7)

template<typename T> T gcd(T a, T b) { if (a == 0) return b; return gcd(b % a, a); }
template<typename T> T pow(T a, T b, lli m) {T ans = 1; while (b > 0) { if (b % 2 == 1) ans = ((ans % m) * (a % m)) % m; b /= 2; a = ((a % m) * (a % m)) % m; } return ans % m; }
template<typename T> void tracev(T &a) { for(auto &i:a) { cout<<i<<' '; } cout<<'\n'; }
template<typename T> void tracevv(vector<T> &a) { for(auto &i:a) { tracev(i); } }
template<typename T> void tracevp(vector<T> &a) { for(auto &i:a) { trace2(i.ff, i.ss); } cout<<'\n'; }

int main(){

	lli n, k;
	cin>>n>>k;
	vlli a(n);
	for(int i = 0 ; i < n ; i++) cin>>a[i];
	sort(a.begin(), a.end());
	deque<plli> q;
	q.push_back(mp(a[0], 1));
	for(int i = 1 ; i < n ;i++){
		if(a[i] != a[i-1]){
			q.push_back(mp(a[i],1));
		}
		else{
			lli occ = q.back().ss+1;
			q.pop_back();
			q.push_back(mp(a[i], occ));
		}
	}
	while(q.size() > 1){
		// trace2(q.front().ff, q.front().ss)
		// trace2(q.back().ff, q.back().ss);
		// trace1(k);
		if(q.front().ss <= q.back().ss && k >= q.front().ss){
			
			plli w = q.front();
			q.pop_front();

			lli m = k/w.ss;
			lli next = min(w.ff+m, q.front().ff);

			k -= w.ss*(next-w.ff);
			w.ff = next;
			
			if(w.ff == q.front().ff){
				w.ss += q.front().ss;
				q.pop_front();
				q.push_front(w);
			}
			else{
				q.push_front(w);
			}
		}
		else if(k >= q.back().ss){
			plli w = q.back();
			q.pop_back();

			lli m = k/w.ss;
			lli next = max(w.ff-m, q.back().ff);

			k -= w.ss*(w.ff-next);
			w.ff = next;

			if(w.ff == q.back().ff){
				w.ss += q.back().ss;
				q.pop_back();
			}
			q.push_back(w);
		}
		if(k < q.front().ss && k < q.back().ss) break;
	}
	cout<<q.back().ff-q.front().ff;


	return 0;
}