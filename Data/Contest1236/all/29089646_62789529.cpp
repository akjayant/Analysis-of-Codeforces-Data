#include <bits/stdc++.h>

#define LL long long

using namespace std;

const LL MOD = 1e9+7;

LL power(LL a, LL x){
	if (x == 0)
		return 1;
	LL res = power(a,x/2)%MOD;
	res = (res*res)%MOD;
	if (x%2)
		res = (res*a)%MOD;
	return res;
}

int main(){
	ios_base::sync_with_stdio(false);
	LL n,m;
	cin >> n >> m;
	cout << power(power(2,m)-1,n) << "\n";
}
