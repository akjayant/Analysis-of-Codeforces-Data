#include <bits/stdc++.h>
using namespace std;

int lit_cnt[30];
int idx[30];
bool polowa[30];
vector <pair<int,int>> zamiany;
vector <int> pos[30];

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int q;
	cin >> q;
	while (q--){
		int n;
		cin >> n;
		string s, t;
		cin >> s >> t;
		for (int i = 1; i <= 26; ++i){
			lit_cnt[i] = 0;
			idx[i] = 0;
			polowa[i] = false;
			pos[i].clear();
		}
		zamiany.clear();
		for (int i = 0; i < n; ++i){
			lit_cnt[s[i]-'a'+1]++;
			lit_cnt[t[i]-'a'+1]++;
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

		for (int i = 0; i < n; ++i){
			if (s[i] == t[i])
				continue;
			int lit_idx = t[i]-'a'+1;
			for (int j = i+1; j < t.size(); ++j){
				if (t[i] == t[j]){
					zamiany.push_back({i,j});
					swap(s[i],t[j]);
					break;
				}
			}
			if (s[i] == t[i])
				continue;
			for (int j = i+1; j < s.size(); ++j){
				if (t[i] == s[j]){
					zamiany.push_back({j,n-1});
					swap(s[j], t[n-1]);
					zamiany.push_back({i, n-1});
					swap(s[i], t[n-1]);
					break;
				}
			}
			if (s[i] != t[i]){
				zle = true;
				break;
			}
		}
		if (zle){
			cout << "No\n";
			continue;
		}
		cout << "Yes\n";
		cout << zamiany.size() << "\n";
		for (auto u: zamiany)
			cout << u.first+1 << " " << u.second+1 << "\n";
	}
}