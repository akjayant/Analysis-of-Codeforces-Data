#include <bits/stdc++.h>
#define ll long long
#define ld long double
#pragma 03
using namespace std;
int main(){
	int k;
	string s, t;
	cin >> k;
	int x;
	string diff;
	string diff2;
	int dff = 0;
	for (int i = 0; i<k; i++){
		dff = 0;
		diff = "";
		diff2 = "";
		cin >> x >> s >> t;
		for (int j = 0; j<x; j++){
			if (s[j] != t[j]){
				diff.push_back(s[j]);
				diff2.push_back(t[j]);
				dff++;
			}
		}
		if (dff != 2) cout << "No\n";
		else{
			if (diff[0] == diff[1] && diff2[0] == diff2[1]) cout << "Yes\n";
			else cout << "No\n";
		}
	}
	return 0;
}
 
