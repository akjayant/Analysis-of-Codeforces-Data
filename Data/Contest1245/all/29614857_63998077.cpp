#pragma GCC optimize(2)
#include<bits/stdc++.h>
//#define int long long
using namespace std;
int T,a,b;
signed main(){
	cin>>T;
	while(T--){
		cin>>a>>b;
		if(__gcd(a,b)==1)	puts("Finite");
		else	puts("Infinite"); 
	}
	return 0;
}

