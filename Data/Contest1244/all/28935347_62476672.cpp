#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define MOD 1000000007

#define N 100003

bool v[N];

int main(){
	ll n, p, w, d;

	cin >> n >> p >> w >> d;
	ll pm = p % w;
	ll pd = d % w;
	ll y = 0, a = 0;
	for(; v[a] == 0; a = (a + pd) % w, y ++){
		v[a] = 1;
		if(a == pm) break;
	}

	ll x = (p - 1LL * y * d) / w;

	if(a != pm || y + x > n || y * d > p)
		cout << "-1\n";
	else{
		cout << x << ' ' << y << ' ' << n - x - y << '\n';
	}
}