#include <bits/stdc++.h>
using namespace std;
#define int long long

const int MOD = 1E9+7;

string s;
int n;


signed main(){
	cin >> s;
	n = s.length();
	int a = 1, b = 1, c = 1;
	if(s[0] == 'm' || s[0] == 'w'){
		cout << "0";
		return 0;
	}
	for(int i=2; i<= n; ++i){
		if(s[i-1]==s[i-2] && (s[i-1] == 'u' || s[i-1] == 'n')){
			c = a+b;
			c%=MOD;
		}
		else if(s[i-1]=='m' || s[i-1] == 'w'){
			cout << "0\n";
			return 0;
		}
		else c= b;
		a=b;
		b=c;
	}
	cout << c <<"\n";
}
