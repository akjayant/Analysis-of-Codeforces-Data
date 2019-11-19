//Suleyman Atayew

#include <algorithm>
#include <iostream>
#include <string.h>
#include <stdio.h>
#include <vector>
#include <queue>
#include <cmath>
#include <map>
#include <set>

#define N 100010
#define ff first
#define ss second
#define pb push_back
#define ll long long
#define inf 1000000007
#define pii pair <ll, ll>

using namespace std;

ll n, p, w, d;

int main()
{
	cin >> n >> p >> w >> d;
	
	if(n*w < p) {
		cout << -1;
		return 0;
	}
	
	ll a = p % w;
	for(ll i = 0; i <= 1000000; i++) {
		a %= d;
		
		if(a == 0) {
			ll x = p / w - i;
			ll y = (p - w * (p / w - i)) / d;
			
			if(x >= 0 && x + y <= n) {
				cout << x << " " << y << " " << n-x-y;
				return 0;
			}
		}
		
		a += w%d;
	}
	
	cout << "-1";
}