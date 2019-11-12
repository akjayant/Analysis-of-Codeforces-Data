#include <iostream>
#include <cstdio>
#include <vector>
#include <math.h>
#include <string.h>
#include <algorithm>
#include <queue>
#include <stack>
#include <unordered_map>
#include <array>
#include <set>
#include <bitset>

using namespace std;

void solve(){
	int a, b, c;
	cin >> a >> b >> c;
	int sol=0;
	if(b*2>c){
		sol+=c/2*3;
		b-=c/2;
	}
	else{
		sol+=b*3;
		b=0;
	}
	if(a*2>b){
		sol+=b/2*3;
		a-=b/2;
	}
	else{
		sol+=a*3;
		a=0;
	}
	cout << sol << '\n';
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