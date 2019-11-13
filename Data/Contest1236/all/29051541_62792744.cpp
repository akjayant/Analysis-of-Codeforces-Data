#include<bits/stdc++.h>

using namespace std;

#define int long long
const int mod = 1000000007;

int powmod(int a,int b){
	int res = 1;
	while(b > 0){
		if(b % 2 == 0) a *= a, a %= mod , b /= 2;
		else res *= a,res %= mod , b --;
	}	
	return res;
}

signed main(){
	int n,m;
	cin >> n >> m;
	
	int h = powmod(2,m) - 1;
	cout << powmod(h,n) << endl;
}
