#include <bits/stdc++.h>

using namespace std;

int main(){
	int q;
	cin >> q;
	while(q--){
		int n, cnt = 0;
		cin >> n;

		string a, b;
		cin >> a >> b;

		set<pair<char, char>> s; 
		for(int i = 0;i < n;i++)
			if(a[i] != b[i])
				cnt++, s.emplace(a[i], b[i]);
		// dbg(s, cnt);
		if(cnt == 1 || cnt > 2 || s.size() == 2){
			cout << "No\n";
			continue;
		}
		if(cnt == 0 || s.size() == 1){
			cout << "Yes\n";
			continue;
		}
		cout << "No\n";
	}
}