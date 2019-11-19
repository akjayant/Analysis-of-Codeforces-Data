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
		string s;
		cin >> s;
		int pos = -1;
		int maxi = 0;
		for(int i = s.length() - 1; i >= 0; i--){
			if(s[i] == '1'){
				maxi = max(maxi, 2 * (i + 1));
				pos = i;
				break;
			}
		}
		for(int i = 0; i < s.length(); i++){
			if(s[i] == '1'){
				maxi = max(maxi, 2 * (n - i));
				pos = i;
				break;
			}
		}
		if(pos == -1){
			cout << n << '\n';
		}
		else cout << maxi << '\n';
	}

}