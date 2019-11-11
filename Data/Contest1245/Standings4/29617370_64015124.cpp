#include<bits/stdc++.h>
using namespace std;
#define int int64_t
typedef pair<int, int> pii;

int mod=1000000007;

int fibonacci[100100]; //modulo 1b7

int32_t main(){
	string s; cin >> s;
	fibonacci[0]=1;
	fibonacci[1]=1;
	for(int i=2; i<100000; ++i) fibonacci[i]=(fibonacci[i-1]+fibonacci[i-2])%mod;
	int len=s.length();
	int ans=1;
	int u=0;
	int n=0;
	for(int i=0; i<len; ++i){
		if(s[i] == 'w' || s[i] == 'm'){
			cout << 0 << endl;
			exit(0);
		}
		if(s[i] == 'u'){
			++u;
			ans*=fibonacci[n];
			ans%=mod;
			n=0;
		}
		else if(s[i] == 'n'){
			++n;
			ans*=fibonacci[u];
			ans%=mod;
			u=0;
		}
		else {
			ans*=fibonacci[u];
			ans%=mod;
			ans*=fibonacci[n];
			ans%=mod;
			u=n=0;
		}
	}
	ans*=fibonacci[u];
	ans%=mod;
	ans*=fibonacci[n];
	ans%=mod;
	u=n=0;
	cout << ans << endl;
}
