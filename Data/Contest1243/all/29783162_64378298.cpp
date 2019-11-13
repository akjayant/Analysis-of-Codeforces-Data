#include <bits/stdc++.h>

#define optimizar_io ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;

int main(){
	optimizar_io;
	int T;
	cin >> T;
	for (int t = 0; t < T; t++){
		int l;
		cin >> l;
		string s1, s2;
		cin >> s1 >> s2;
		vector<int> dif;
		for (int i = 0; i < s1.size(); i++){
			if (s1[i] != s2[i]){
				dif.push_back(i);
			}
		}
		if (dif.size() == 0){
			cout << "Yes" << endl;
		} else if (dif.size() == 2){
			swap(s1[dif[0]], s2[dif[1]]);
			if (s1 == s2)
				cout << "Yes" << endl;
			else
				cout << "No" << endl;
		} else {
			cout << "No" << endl;
		}
	}
	return 0;
}
