#include <bits/stdc++.h>
#define ios ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define pll pair <long long,long long>
#define f first
#define s second
#define ll long long
#define pss pair <string, string>
#define pls pair <long long , string >
#define psl pair <string , long long >
using namespace std;
int main () {
	ios;
	ll n;
	cin>>n;
	ll gcd=0;
	for (ll k=2;k<=sqrt(n);k++) {
		if (n%k==0) {
			gcd=__gcd(gcd,k);
			gcd=__gcd(gcd,n/k);
		}
	}
	if (gcd==0) cout<<n;
	else cout<<gcd;
	return 0;
}
