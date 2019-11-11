#include<bits/stdc++.h>

using namespace std;
const int MAXN = 100100;
#define int long long
const int mod = 1000000007;

int memo[MAXN];

int pd(int pos){
	
	if(pos < 0) return 0;
	if(pos == 0) return 1;
	if(memo[pos] != -1) return memo[pos]; 
	
	int com = pd(pos - 2);
	int sem = pd(pos - 1);
	
	return memo[pos] = (com + sem) % mod;
}

signed main(){
	memset(memo,-1,sizeof memo);
	
	int res = 1;
	
	string s;
	cin >> s;
	
	s += "#";
	
	int soma = 0;
	for(int i = 0;i < s.size();i++){
		if(i > 0 && s[i] != s[i - 1]){
			if(soma > 0) res *= pd(soma) , res %= mod;
			//cout << "| " << i << " " << soma << endl;
			soma = 0;
		}
		
		if(s[i] == 'm' || s[i] == 'w'){
			cout << 0 << endl;
			return 0;
		}
		
		if(s[i] == 'u') soma ++;
		if(s[i] == 'n') soma ++;
	}
	
	cout << res << endl;
}