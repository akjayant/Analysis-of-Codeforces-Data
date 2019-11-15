/*
* @Author: SajidZakaria
* @Date:   2019-11-06 21:03:09
* @Last Modified by:   SajidZakaria
* @Last Modified time: 2019-11-06 21:15:01
*/

#include<bits/stdc++.h>
using namespace std;

int main(){
	int k, n;
	string s, t;
	cin >> k;

	while(k--) {
		cin >> n >> s >> t;
		vector< int > v;

		for(int i=0; i<n; i++) if(s[i] != t[i]) v.push_back(i);
		int x = v.size();
		if(x == 1 or x > 2) cout << "No" << endl;
		else if(x == 0) cout << "Yes" << endl;
		else if(s[v[0]] == s[v[1]] and t[v[1]] == t[v[0]]) cout << "Yes" << endl;
		else cout << "No" << endl;
		v.clear();
	}
}