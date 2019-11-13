#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef long double ld;
typedef pair<ll, ll> ii;
typedef vector<ii> vii;
typedef vector<ll> vi;

#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define mod 1000000007
#define INF 1000000000ll
#define MAX 100005

void init(){
	return;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	init();
	int k;
	cin >> k;
	while(k--){
		int n;
		cin >> n;
		string s, t;
		cin >> s;
		cin >> t;
		int cnt[26];
		memset(cnt, 0, sizeof(cnt));
		for(int i = 0; i<n; i++){
			cnt[s[i]-'a']++;
			cnt[t[i]-'a']++;
		}
		bool flag = false;
		for(int i = 0; i<26; i++){
			if(cnt[i]%2 == 1){
				cout << "No" << endl;
				flag = true;
				break;
			}
		}
		if(flag)continue;
		cout << "Yes" << endl;
		vector<pair<int, int>> ans;
		for(int i = 0; i<n; i++){
			if(s[i] == t[i])continue;
			else{
				int idx = -1;
				for(int j = i+1; j<n; j++){
					if(s[j] == s[i]){
						idx = j;
						break;
					}
				}
				if(idx != -1){
					ans.pb(mp(idx, i));
					s[idx] = t[i];
				}
				else{
					for(int j = i+1; j<n; j++){
						if(t[j] == s[i]){
							idx = j;
							break;
						}
					}
					ans.pb(mp(idx, idx));
					ans.pb(mp(idx, i));
					t[idx] = s[idx];
					s[idx] = t[i];
				}
			}
		}
		cout << ans.size() << endl;
		for(auto it : ans){
			cout << it.ff+1 << " " << it.ss+1 << endl;
		}
	}
	//fclose(stdout);
	return 0;
}