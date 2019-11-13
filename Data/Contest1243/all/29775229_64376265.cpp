# include <bits/stdc++.h>
using namespace std;
int main(){
	int q;
	cin >> q;
	while(q --){
		int n;
		string s , t;
		cin >> n >> s >> t;
		vector < int > idx;
		for(int i = 0; i < n; i ++) if(s[i] != t[i]) idx.push_back(i);
		if(idx.size() != 2){
			cout << "No\n";
			continue;
		}
		string S = s , T = t;
		swap(s[idx[0]] , t[idx[1]]);
		swap(S[idx[1]] , T[idx[0]]);
		if(s == t || S == T){
			cout << "Yes\n";
		}
		else{
			cout << "No\n";
		}
	}
}