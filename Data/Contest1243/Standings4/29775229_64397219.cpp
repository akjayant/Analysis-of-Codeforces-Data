# include <bits/stdc++.h>
using namespace std;
void solve(){
	int n;
	string s , t;
	cin >> n >> s >> t;
	set < int > F1[27] , F2[27];
	int X1[27] , X2[27];
	for(int i = 0; i < 27; i ++) X1[i] = X2[i] = 0;
	for(int i = 0; i < n; i ++) F1[s[i] - 'a'].insert(i) , F2[t[i] - 'a'].insert(i) , X1[s[i] - 'a'] ++ , X2[t[i] - 'a'] ++;
	for(int i = 0; i < 26; i ++)
		if(X1[i] + X2[i] & 1){
			cout << "No\n"; 
			return;
		} 
	vector < pair < int , int > > res;
	for(int i = 0; i < n; i ++){
		for(int j = 0; j < 26; j ++){
			while(F2[j].size() && *F2[j].begin() <= i)F2[j].erase(F2[j].begin());
			while(F1[j].size() && *F1[j].begin() <= i)F1[j].erase(F1[j].begin());
		}
		if(s[i] != t[i]){
			int d = t[i] - 'a' , c = s[i] - 'a';
			if(F1[c].size()){
				int j = *F1[c].begin();
				F1[c].erase(F1[c].begin());
				F1[d].insert(j);
				swap(t[i] , s[j]);
				res.push_back({j + 1 , i + 1});
				continue;
			}
			if(F2[d].size()){
				int j = *F2[d].begin();
				F2[d].erase(F2[d].begin());
				F2[c].insert(j);
				swap(t[j] , s[i]);  
				res.push_back({i + 1 , j + 1});
				continue;
			}
			if(F2[c].size()){
				int j = *F2[c].begin();
				F2[c].erase(F2[c].begin());
				char C = s[j] - 'a';
				F1[C].erase(j);
				F2[C].insert(j);
				F1[c].insert(j);
				swap(t[j] , s[j]);
				res.push_back({j + 1 , j + 1});
				i --;
				continue; 
			}
			if(F1[d].size()){
				int j = *F1[d].begin();
				F1[d].erase(F1[d].begin());
				char D = t[j] - 'a';
				F2[D].erase(j);
				F2[d].insert(j);
				F1[D].insert(j);
				res.push_back({j + 1 , j + 1});
				i --;
				swap(t[j] , s[j]);
				continue;
			}
			cout << "No\n";
			return;
		}
	}
	if(res.size() > 2 * n){
		cout << "No\n";
		return;
	}
	cout << "Yes\n" << res.size() << '\n';
	for(int i = 0; i < res.size(); i ++) cout << res[i].first << " " << res[i].second << '\n';
}
int main(){
	int q;
	cin >> q;
	while(q --){
		solve();
	}
}
