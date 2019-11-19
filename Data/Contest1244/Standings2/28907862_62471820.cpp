#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define pb push_back
#define mp make_pair
#define all(c) (c).begin(),(c).end()
#define int long long
#define M 1000000007
#define pr(...) dbs(#__VA_ARGS__, __VA_ARGS__)
template <class T> void dbs(string str, T t) {cerr << str << " : " << t << "\n";}
template <class T, class... S> void dbs(string str, T t, S... s) {int idx = str.find(','); cerr << str.substr(0, idx) << " : " << t << ", "; dbs(str.substr(idx + 1), s...);}
template <class S, class T>ostream& operator <<(ostream& os, const pair<S, T>& p) {return os << "(" << p.first << ", " << p.second << ")";}
template <class T>ostream& operator <<(ostream& os, const vector<T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class T>ostream& operator <<(ostream& os, const set<T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class S, class T>ostream& operator <<(ostream& os, const map<S, T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class T> void prc(T a, T b) {cerr << "["; for (T i = a; i != b; ++i) {if (i != a) cerr << ", "; cerr << *i;} cerr << "]\n";}
// Use pr(a,b,c,d,e) or cerr<<anything or prc(v.begin(),v.end()) or prc(v,v+n)

const int N = 100007;

void init()
{

}

void solve()
{
	int i, j, k, n, q;
	int x, y, l, r;
	cin >> n >> k;
	map <int,int> mp;
	for(i=0;i<n;i++){
		cin >> x;
		mp[x]++;
	}

	while(k>0 && mp.size()>1){
		int f_mn = mp.begin()->second, f_mx = mp.rbegin()->second;
		int mn = mp.begin()->first, mx = mp.rbegin()->first;
		if(f_mn<f_mx){
			mp.erase(mn);
			int next_mn = mp.begin()->first;
			int diff = next_mn - mn;
			if(k>=diff*f_mn){
				mp[next_mn] += f_mn;
				k -= diff*f_mn;
			}
			else{
				int add = k/f_mn;
				mp[mn+add] = f_mn;
				k = 0;
			}
		}
		else{
			mp.erase(mx);
			int next_mx = mp.rbegin()->first;
			int diff = mx - next_mx;
			if(k>=diff*f_mx){
				mp[next_mx] += f_mx;
				k -= diff*f_mx;
			}
			else{
				int add = k/f_mx;
				mp[mx-add] = f_mx;
				k = 0;
			}
		}
	}
	cout << (mp.rbegin()->first) - (mp.begin()->first) << endl;
}

int32_t main()
{
	fastio;
	int t;
	// cin >> t;
	t = 1;
	for(int pp=1;pp<=t;pp++){
		solve();
	}
	return 0;
}