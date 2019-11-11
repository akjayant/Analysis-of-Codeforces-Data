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

int gcd(int a, int b){
	return ((b)?gcd(b,a%b):a);
}

int main(void){
	int t,k,a,b;
	cin >> t;
	for(k=0; k<t; ++k){
		cin >> a >> b;
		cout << ((gcd(a,b)>1)?"Infinite":"Finite") << endl;
	}
	return 0;
}
