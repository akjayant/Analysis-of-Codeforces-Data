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

int n;
ll memo[100100];
bool done[100100];
string s;

ll solve(int i){
	if(done[i]){
		return memo[i];
	}
	done[i] = true;
	if(i==n){
		return memo[i] = 1ll;
	}
	if(s[i]=='m' || s[i]=='w'){
		return memo[i] = 0ll;
	}
	add_mod(memo[i],solve(i+1));
	if(s[i]==s[i+1] && (s[i]=='u' || s[i]=='n')){
		add_mod(memo[i],solve(i+2));
	}
	return memo[i];
}

int main(void){
	cin >> s;
	n = s.l_ength();
	s.push_back('@');
	cout << solve(0) << endl;
	return 0;
}
