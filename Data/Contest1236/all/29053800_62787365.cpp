#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false); cin.tie(0);
#define MOD 1000000007
using namespace std;

long long int pw(long long int n,long long int m){
	long long int re=1,base=n%MOD;
	while(m>0){
		if(m&1){
			re=(re*base)%MOD;
			m--;
		}
		else{
			base=(base*base)%MOD;
			m/=2;
		}
	}
	return re%MOD;
}

int main(){
//	IOS;
	long long int n,m;
	cin >> n >> m;
	cout << pw(pw(2,m)-1,n) << '\n';
	return 0;
}
