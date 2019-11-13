#include <bits/stdc++.h>
using namespace std;

int lit_cnt[30];
vector <int> diffs;


int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int q;
	cin >> q;
	while (q--){
		diffs.clear();
		int n;
		cin >> n;
		string s, t;
		cin >> s >> t;
		for (int i = 1; i <= 26; ++i)
			lit_cnt[i] = 0;
		for (int i = 0; i < n; ++i){
			lit_cnt[s[i]-'a'+1]++;
			lit_cnt[t[i]-'a'+1]++;
			if (s[i] != t[i])
				diffs.push_back(i);
		}
		bool zle = false;
		for (int i = 1; i <= 26; ++i){
			if (lit_cnt[i] % 2 != 0)
				zle = true;
		}
		if (zle){
			cout << "No\n";
			continue;
		}
		if (diffs.size() != 2 && diffs.size() != 0){
			cout << "No\n";
			continue;
		}

		if (diffs.size() == 0 || (s[diffs[0]] == s[diffs[1]] && t[diffs[1]] == t[diffs[0]]))
			cout << "Yes\n";
		else
			cout << "No\n";
	}
}