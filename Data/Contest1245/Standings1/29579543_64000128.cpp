#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
const int INF = (1<<30);
const ll INFLL = (1ll<<60);
const ll MOD = (ll)(1e9+7);

#define l_ength size

void mul_mod(ll& a, ll b){
	a *= b;
	a %= MOD;
}

void add_mod(ll& a, ll b){
	a = (a<MOD)?a:(a-MOD);
	b = (b<MOD)?b:(b-MOD);
	a += b;
	a = (a<MOD)?a:(a-MOD);
}

int main(void){
	int k,t,a,b,c,n,i,w;
	string s,ans;
	cin >> t;
	for(k=0; k<t; ++k){
		ans = ""; w = 0;
		cin >> n;
		cin >> a >> b >> c;
		// a - R, b - P, c - S
		cin >> s;
		for(i=0; i<n; ++i){
			if(s[i]=='R'){
				if(b){
					--b; ++w;
					ans.push_back('P');
					continue;
				}
			}else if(s[i]=='P'){
				if(c){
					--c; ++w;
					ans.push_back('S');
					continue;
				}
			}else{
				if(a){
					--a; ++w;
					ans.push_back('R');
					continue;
				}
			}
			ans.push_back('@');
		}
		if(w<(n+1)/2){
			cout << "No" << endl;
			continue;
		}
		cout << "Yes" << endl;
		for(i=0; i<n; ++i){
			if(ans[i]=='@'){
				if(a){
					--a;
					cout << "R";
				}else if(b){
					--b;
					cout << "P";
				}else{
					--c;
					cout << "S";
				}
			}else{
				cout << ans[i];
			}
		}
		cout << endl;
	}
	return 0;
}
