#include <bits/stdc++.h>
#define ll long long
#define ld long double
#pragma 03
using namespace std;
int main(){
	int k, n;
	string s, t;
	vector <int> sol, sol2;
	cin >> k;
	for (int x = 0; x<k; x++){
		bool ans = true;
		sol.clear(); sol2.clear();
		cin >> n >> s >> t;
		for (int i = 0; i<n; i++){
			if (s[i] != t[i]){
				for (int j = i+1; j<n; j++){
					if (s[j] == t[i]){
						swap(s[j], t[j]);
						sol.push_back(j+1);
						sol2.push_back(j+1);
					}
					if (t[j] == t[i]){
						swap(s[i], t[j]);
						sol.push_back(i+1);
						sol2.push_back(j+1);
						break;
					}
				}
			}
			if (s[i] != t[i]) ans = false;
		}
		if (ans == false) cout << "No\n";
		else{
			cout << "Yes\n";
			cout << sol.size() << endl;
			for (int i = 0; i<sol.size(); i++) cout << sol[i] << " " << sol2[i] << endl;
		}
	}
	return 0;
}
 
