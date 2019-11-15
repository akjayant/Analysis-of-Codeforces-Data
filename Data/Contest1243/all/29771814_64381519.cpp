#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;

int a[N];
int main(){
	fast;
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		string s, ss;
		cin >> s >> ss;
		string ans = "No";
		if(s == ss){
			ans = "Yes";
		}
		else{
			vector<pair<char, char> > v;
			int ct = 0;
			for(int i = 0; i < n; i++){
				if(s[i] != ss[i]){
					ct++;
				}
			}
			if(ct == 2){
				for(int i = 0; i < n; i++){
					if(s[i] != ss[i]){
						v.push_back({s[i], ss[i]});
					}
				}
				if(v[0].first == v[1].first && v[0].second == v[1].second){
					ans = "Yes";
				}
			}
		}
		cout << ans << "\n";
	}
	
	return 0;
}
