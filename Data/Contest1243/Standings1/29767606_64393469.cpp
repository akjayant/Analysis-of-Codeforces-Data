#include<bits/stdc++.h>
#define MOD 1000000007
#define ll long long
#define mp make_pair
#define pb push_back 
using namespace std;
int mk[30];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	while(t--){
		memset(mk, 0, sizeof(mk));
		int n;
		cin >> n;
		string s, t;
		cin >> s >> t;
		for(int i = 0; i < n; i++){
			mk[s[i] - 'a']++;
			mk[t[i] - 'a']++;
		}
		int nop = 0;
		for(int i = 0; i < 26; i++){
			if(mk[i] % 2){
				cout << "No\n";
				nop = 1;
				break;
			}
		}
		if(nop)
			continue;
		vector<pair<int, int> > ans;
		for(int i = 0; i < n - 1; i++){
			if(t[i] == s[i])
				continue;
			int done = 0;
			for(int j = i + 1; j < n; j++){
				if(s[j] == s[i]){
					ans.pb(mp(j, i));
					swap(t[i], s[j]);
					done = 1;
					break;
				}
			}
			if(done)continue;
			for(int j = i + 1; j < n; j++){
				if(t[j] == s[i]){
					ans.pb(mp(n - 1, j));
					ans.pb(mp(n - 1, i));
					swap(s[n - 1], t[j]);
					swap(s[n - 1], t[i]);
					break;
				}
			}
		}
		cout << "YES\n";
		if(ans.size() == 0){
			ans.pb(mp(0, 0));
		}
		//cerr << s << " " << t << '\n';
		cout << ans.size() << '\n';
		for(int i = 0; i < ans.size(); i++)
			cout << ans[i].first + 1 << " " << ans[i].second + 1 << '\n';
	}


}