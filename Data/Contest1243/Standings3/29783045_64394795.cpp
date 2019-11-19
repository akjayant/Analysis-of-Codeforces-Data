#include <bits/stdc++.h>
using namespace std;
long long n;
vector<long long> primes;
int main (){
ios::sync_with_stdio(0);
cin.tie(0); cout.tie(0);
cin >> n; long long x=n;
for (int i=2; i<=sqrt(x); i++){
	if (x%i==0){
		primes.push_back(i);
		while (x%i==0) x/=i;
	}
}
if (x!=1) primes.push_back(x);
if (primes.size()!=1) cout << "1";
else cout << primes[0];
return 0;
}

