#include <iostream>
#include <cstdio>
#include <algorithm>
#include <math.h>
#include <string.h>
#include <vector>
#include <queue>
#include <set>
#include <stack>
#include <unordered_map>
#include <bitset>
#include <array>

using namespace std;

void solve(){
	int a, b, c, d, k;
	cin >> a >> b >> c >> d >> k;
	if((a+c-1)/c+(b+d-1)/d>k){
		cout << -1 << '\n';
	}
	else{
		cout << (a+c-1)/c << " " << (b+d-1)/d << '\n';
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	for(int i=0; i<t; i++){
		solve();
	}
	return 0;
}