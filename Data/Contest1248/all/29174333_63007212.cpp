/**
	WGkKWGkF
	@author: harshkirat2
*/
#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define vec vector
#define psb push_back
#define ppb pop_back
#define mkp make_pair
#define fst first
#define scd second
#define ins insert
#define psf push_front
#define ppf pop_front
using namespace std;
int main() {
	ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	ll i, fib[100002], modv=1e9+7, dib[100002];
	fib[1]=2; fib[2]=4;
	dib[1]=0; dib[2]=2; 
	for(i=3; i<100002; i++){
		fib[i] = (fib[i-1] + fib[i-2])%modv;
		dib[i] = ((dib[i-1] + dib[i-2])%modv+2)%modv;
	}
	ll n, m;
	cin >> n >> m;
	if(n>m)
		swap(n,m);
	cout<<(dib[n]+fib[m])%modv;
	return 0;
}

