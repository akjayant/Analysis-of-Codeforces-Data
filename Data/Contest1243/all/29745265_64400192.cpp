#include <bits/stdc++.h>
  
using namespace std;
  
template<class T> void ckmin(T &a, T b) { a = min(a, b); }
template<class T> void ckmax(T &a, T b) { a = max(a, b); }
  
#define pb push_back
#define mp make_pair
#define cotu cout
#define itn int
#define Red ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define F first
#define S second
#define sz(x) (int)x.size()
#define all(x) (x).begin(), (x).end()
#define rep(i, n) for(int i = 0; i < n; ++i)
#define repr(i,n) for(int i = n - 1; i >= 0; --i)
#define Rep(i, a, n) for(int i = (a); i <=(n); ++i)
#define repst(i, n) for(auto it = n.begin(); it != n.end(); ++it)
#define Repr(i, a, n) for(int i = (n); i >= (a); --i)
  
#define ordered_set tree<int , null_type,less<int >, rb_tree_tag,tree_order_statistics_node_update> 
  
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 
  
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
  
const int inf = int(1e9);
const int mod = inf + 7;
const int N = 1e7 + 555;
const double PI = acos(-1.0);
map<char, set<int> > v1, v2;
int cnt[26];
void solve()
{
	int n;
	cin >> n;
	string s, t;
	cin >> s >> t;
	for(int i = 0; i < 26; ++i) cnt[i] = 0;
	v1.clear();
	v2.clear();
	for(int i = 0; i < n; ++i) {
		cnt[s[i] - 'a']++;
		v1[s[i]].insert(i);
	}
	for(int i = 0; i < n; ++i) {
		cnt[t[i] - 'a']++;
		v2[t[i]].insert(i);
	}
	for(int i = 0; i < 26; ++i){
		if(cnt[i] % 2){
			cout << "No" << endl;
			return;
		}
	}
	vector<pair<int, int> > ans;
	cout << "Yes" << endl;
	for(int i = 0; i < n; ++i){
		if(s[i] == t[i]) {
			v1[s[i]].erase(v1[s[i]].find(i));
			v2[t[i]].erase(v2[t[i]].find(i));
		}
		else{
			if(v2[t[i]].size() > 1){
				auto it = v1[s[i]].find(i);
				auto jt = v2[t[i]].begin();
				jt++;
				int ff = *it;
				int ss = *jt;
				ans.push_back({ff, ss});
				v1[s[i]].erase(it);
				v2[t[i]].erase(jt);
				v2[t[i]].erase(v2[t[i]].find(i));
				v2[s[i]].insert(ss);
				swap(s[ff], t[ss]);
			}
			else{
				auto it = v1[s[i]].find(i);
				auto jt = v2[t[i]].find(i);
				ans.pb({*it, *jt});
				int ff = *it;
				int ss = *jt;
				v1[s[i]].erase(it);
				v2[t[i]].erase(jt);
				swap(s[ff], t[ss]);
				v1[s[i]].insert(ff);
				v2[t[i]].insert(ss);
				it = v1[s[i]].find(i);
				jt = v2[t[i]].find(i);
				it++;
				ff = *it;
				ss = *jt;
				ans.push_back({ff, ss});
				v1[s[i]].erase(v1[s[i]].find(i));
				v2[t[i]].erase(v2[t[i]].find(i));
				v1[t[i]].insert(ff);
				swap(s[ff], t[ss]);
			}
		}
	}
	cout << ans.size() << endl;
	rep(i, ans.size()){
		cout << ans[i].F + 1 << " " << ans[i].S + 1 << endl;
	}
}
 
int main()
{
    Red;
    int T;
    cin >> T;
    while(T--)
    solve();
    return 0;
}