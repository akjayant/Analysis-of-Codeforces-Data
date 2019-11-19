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
string s;
int dx[] = {0,0,-1,1,0,0};
int dy[] = {-1,1,0,0,0,0};
vector < int > L;

int solve( int l, int r ){
	int ans = 0;
	ans = max( ans, n - r + l + 1);
	ans = max( ans, n - l);
	ans = max( ans, r + 1);
	return ans;
}

int main(){

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int tc;
	cin >> tc;
	while ( tc-- ){
		cin >> n;
		cin >> s;
		int ans = 0;
		L.clear();
		for ( int i = 0; i < n; i++ ){
			if ( s[i] == '1' ) L.push_back(i);
		}

		ans = max( ans, n );
		for ( int l : L ){
			ans = max( ans, 2 * max(n - l, l + 1) );
			for ( int r : L ){
				if ( l >= r ) continue;
				ans = max( ans, r-l+1 + solve(l,r) );
			}
		}

		cout << ans << endl;
	}
	return 0;
}