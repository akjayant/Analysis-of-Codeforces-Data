#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<utility>
using namespace std;

int k;
int literki[30];
vector<pair<int, int> > wyp;

int main(){
	cin >> k;
	while(k--){
		int n;
		cin >> n;
		string s, t;
		cin >> s >> t;
		for(int i = 0; i < n; i++){
			literki[s[i] - 'a']++;
			literki[t[i] - 'a']++;
		}
		bool czy = true;
		for(int i = 0; i < 26; i++){
			if(literki[i]%2 == 1){
				czy = false;
			}
			literki[i] = 0;
		}
		if(!czy){
			cout << "No\n";
			continue;
		}
		for(int i = 0; i < n; i++){
			if(s[i] == t[i]) continue;
			for(int j = i + 1; j < n; j++){
				if(s[j] == s[i]){
					wyp.push_back(make_pair(j, i));
					char x = t[i];
					t[i] = s[j];
					s[j] = x;
					break;
				}
				if(t[j] == s[i]){
					wyp.push_back(make_pair(j, j));
					wyp.push_back(make_pair(j, i));
					char x = s[j];
					s[j] = t[i];
					t[i] = t[j];
					t[j] = x;
					break;
				}
			}
		}
		cout << "Yes\n";
		cout << wyp.size() << "\n";
		for(int i = 0; i < wyp.size(); i++){
			cout << wyp[i].first + 1 << " " << wyp[i].second + 1 << "\n";
		}
		wyp.clear();
		wyp.resize(0);
	}
	return 0;
}