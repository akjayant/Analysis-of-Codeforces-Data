#include <bits/stdc++.h>
using namespace std;
const long long mod=1e9+7;
long long powmod(long long pmx, long long pmn, long long pmm){
	if(pmn == 0) return 1;
	if(pmn % 2 == 0) return powmod((pmx * pmx) % pmm, pmn / 2, pmm);
	else return (pmx * powmod(pmx, pmn - 1, pmm)) % pmm;
} 
int main() {
	// your code goes here
	int r,q;
	q=1;
	//cin >> q;
	for(r=0;r<q;r++){
		long long n,m;
		cin >> n >> m;
		cout << powmod(((powmod(2,m,mod)+mod-1)%mod),n,mod) << endl;
	}
	return 0;
}