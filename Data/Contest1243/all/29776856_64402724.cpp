/*
* @Author: SajidZakaria
* @Date:   2019-11-06 21:03:09
* @Last Modified by:   SajidZakaria
* @Last Modified time: 2019-11-06 22:16:25
*/

#include<bits/stdc++.h>
using namespace std;

int cnt[26];

int main(){
	int k, n;
	string s, t;
	cin >> k;

	while(k--) {
		cin >> n >> s >> t;

		vector< pair<int, int> > v;
		for(int i=0; i<n; i++) 
			if(s[i] != t[i]) cnt[t[i]-'a']++, cnt[s[i]-'a']++;

		for(int i=0; i<26; i++) if(cnt[i] % 2 == 1) {cout << "No" << endl; goto done;}
		cout << "Yes" << endl;

		for(int i=0; i<n-1; i++) {
			if(s[i] == t[i]) continue;
			for(int j=i+1; j<n; j++) {
				if(s[i] == t[i]) continue;
				if(s[i] == s[j]) {v.push_back({j, i}), swap(s[j], t[i]); break;}
				else if(s[i] == t[j]) {
					v.push_back({i+1, j}); swap(s[i+1], t[j]);
					v.push_back({i+1, i}); swap(s[i+1], t[i]);
					break;
				}
			}
		}
		cout << v.size() << endl;
		assert(v.size() <= 2 * n);
		for(auto i : v) cout << i.first + 1 << ' ' << i.second + 1 << endl;	

		done: ;
		v.clear();
		memset(cnt, 0, sizeof cnt);
	}
}