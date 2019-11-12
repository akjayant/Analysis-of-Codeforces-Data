#include<bits/stdc++.h>
#define MOD 1000000007
#define ll long long
#define mp make_pair
#define pb push_back 
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		string s, t;
		cin >> s >> t;
		vector<int> df;
		for(int i = 0; i < s.length(); i++){
			if(s[i] != t[i]){
				df.pb(i);
			}
		}
		if(df.size() == 1 || df.size() > 2){
			cout << "No\n";
		}
		else{
			if(!df.size()){
				cout << "Yes\n";
			}
			else{
				//cerr << df[0] << " " << df[1] << '\n';
				if(s[df[0]] == s[df[1]] && t[df[1]] == t[df[0]]){
					cout << "Yes\n";
				}
				else cout << "No\n";
			}
		}
	}


}