#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL MOD=1000000007;

LL modex(LL b, LL e , LL m){
	LL r=1;
	while(e>0){
		if((e&1)==1){
			r=(r*b)%m;
		}
		e >>=1;
		b=(b*b) %m;
	}
	return (LL)r;
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	LL n,m;
	cin >> n >> m;
	LL base=(modex(2,m,MOD)-1+MOD)%MOD;
	cout << modex(base,n,MOD) << endl;
	return 0;
}


