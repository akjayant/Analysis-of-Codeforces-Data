#include<iostream>
#include<algorithm>
#include<string>
#include<utility>
using namespace std;

int k;
int literki[30];

int main(){
	cin >> k;
	for(int l = 1; l <= k; l++){
		int n;
		cin >> n;
		string s, t;
		cin >> s >> t;
		pair<int, int> zmiana = make_pair(n, n);
		int zmiany = 0;
		bool czy = false;
		for(int i = 0; i < n; i++){
			if(s[i] != t[i]){
				zmiany++;
				if(zmiany == 1) zmiana.first = i;
				if(zmiany == 2) zmiana.second = i;
			}
			else{
				literki[s[i] - 'a']++;
				if(literki[s[i] - 'a'] >= 2) czy = true;
			}
		}
		if(zmiany == 1 or zmiany >= 3){
			cout << "No\n";
			continue;
		}
		else if(zmiany == 0 and czy){
			cout << "Yes\n";
			continue;
		}
		else if(zmiany == 0 and !czy){
			cout << "No\n";
		}
		else if(s[zmiana.first] == s[zmiana.second] and t[zmiana.first] == t[zmiana.second]){
			cout << "Yes\n";
		}
		else cout << "No\n";
		for(int i = 0; i < 26; i++){
			literki[i] = 0;
		}
	}
	return 0;
}