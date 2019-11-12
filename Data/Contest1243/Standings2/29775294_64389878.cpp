#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<long long,long long> pll;
#define pb push_back
#define mp make_pair
#define rep(i,n) for(int i=0;i<(n);++i)
constexpr int mod=1000000007;
constexpr int mod1=998244353;
vector<int> dx={0,1,0,-1},dy={-1,0,1,0};
bool inside(int y,int x,int h,int w){
	if(y<h && y>=0 && x<w && x>=0) return true;
	return false;
}





int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	int k;cin >> k;
	while(k--){
		int n;cin >> n;
		string s,t;cin >> s >> t;
		vector<int> cnt(26);
		rep(i,n){
			cnt.at(s.at(i) - 'a')++;
			cnt.at(t.at(i) - 'a')++;
		}
		bool ok = true;
		rep(i,26) if(cnt.at(i) % 2 == 1) ok = false;
		if(!ok){
			cout << "No" << endl;
			continue;
		}
		vector<pii> ans;
		rep(i,n - 1){
			if(s.at(i) == t.at(i)) continue;
			int k = -1;
			for(int j = i + 1; j < n; j++){
				if(s.at(j) == s.at(i)){
					k = j;
					break;
				}
			}
			if(k != -1){
				ans.pb(mp(k, i));
				char c = s.at(k);
				s.at(k) = t.at(i);
				t.at(i) = c;
				continue;
			}
			for(int j = i + 1; j < n; j++){
				if(t.at(j) == s.at(i)){
					k = j;
					break;
				}
			}
			ans.pb(mp(i + 1, k));
			ans.pb(mp(i + 1, i));
			char c = s.at(i + 1);
			s.at(i + 1) = t.at(k);
			t.at(k) = c;
			c = t.at(i);
			t.at(i) = s.at(i + 1);
			s.at(i + 1) = c;
		}
		cout << "Yes" << endl;
		cout << ans.size() << endl;
		rep(i,ans.size()){
			cout << ans.at(i).first + 1 << " " << ans.at(i).second + 1 << endl;
		}
	}
}