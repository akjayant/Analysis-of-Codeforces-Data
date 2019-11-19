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
	int n;
	cin >> n;
	string s;
	cin >> s;
	for(int i=0; i<n; i++){
		if(s[i]=='1'){
			cout << (n-i)*2 << '\n';
			return;
		}
		else if(s[n-i-1]=='1'){
			cout << (n-i)*2 << '\n';
			return;
		}
	}
	cout << n << '\n';
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