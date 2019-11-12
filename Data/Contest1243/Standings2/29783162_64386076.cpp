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
		map<char, int> counter;
		for (int i = 0; i < s1.size(); i++){
			counter[s1[i]]++;
			counter[s2[i]]++;
		}
		bool ok = true;
		for (char c = 'a'; c <= 'z'; c++){
			if (counter[c] % 2) ok = false;
		}
		if (ok){
			cout << "Yes" << endl;
			vector < pair<int, int> > changes;
			for (int i = 0; i < s1.size(); i++){
				if (s1[i] != s2[i]){
					for (int j = i + 1; j < s1.size(); j++){
						if (s1[j] == s1[i]){
							swap(s1[j], s2[i]);
							changes.push_back(make_pair(j, i));
							break;
						} 
						if (s2[j] == s1[i]){
							swap(s2[j], s1[j]);
							swap(s1[j], s2[i]);
							changes.push_back(make_pair(j, j));
							changes.push_back(make_pair(j, i));
							break;
						}
					}
				}
			}
			cout << changes.size() << endl;
			for (int i = 0; i < changes.size(); i++) cout << changes[i].first + 1 << " " << changes[i].second + 1<< endl;
		} else {
			cout << "No" << endl;
		}
	}

	return 0;
}
