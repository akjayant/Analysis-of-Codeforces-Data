#include <bits/stdc++.h>
using namespace std;

int f[300];

int main(){
	int test;
	cin >> test;
	while (test-- > 0){
		int n;
		cin >> n;
		string s, t;
		cin >> s >> t;
		//cout << s << ' ' << t << endl;
		memset(f, 0, sizeof f);
		for (int i=0; i<n; i++){
			f[s[i]]++, f[t[i]]++;
		}
		bool flag = true;
		for (int i='a'; i<'z'; i++){
			if(f[i] & 1) flag = false;
		}
		puts((flag) ? "Yes" : "No");
		if(flag){
			vector < pair < int, int > > ans;
			for (int i=0; i<n; i++){
				if(s[i] != t[i]){
					for (int j=i+1; j<n; j++){
						if(s[j] == s[i]){
							swap(s[j], t[i]);
							ans.push_back({j+1, i+1});
							break;
						}
						if(t[j] == s[i]){
							swap(t[j], s[j]);
							ans.push_back({j+1, j+1});
							swap(s[j], t[i]);
							ans.push_back({j+1, i+1});
							break;
						}
					}
				}
			}
			cout << (int)ans.size() << endl;
			for (int i=0; i<ans.size(); i++){
				cout << ans[i].first << ' ' << ans[i].second << endl;
			}
		}
	}
}
