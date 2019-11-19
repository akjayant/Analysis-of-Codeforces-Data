#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <string>
#include <set>
#include <map>
#include <assert.h>
#include <queue>
#include <deque>
using namespace std;
#define LL long long
#define fi first
#define se second
#define mp make_pair
#define pb push_back

int n;
int a,b,c,d,k;

void solve(){

	for ( int x = 1; x <= k; x++ ){
		for ( int y = 1; y + x <= k; y++ ){
			int A = c * x;
			int B = d * y;
			if ( A >= a && B >= b ){
				cout << x << " " << y << endl;
				return;
			}
		}
	}

	cout << -1 << endl;
}

int main(){

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int tc;
	cin >> tc;
	while ( tc-- ){
		cin >> a >> b >> c >> d >> k;
		solve();
	}
	return 0;
}