#include <iostream>
#include <cstdio>
#include <map>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <string>
#include <deque>
#include <cmath>
#include <queue>
#include <ctime>
#include <utility> // std::pair
#include <functional> // std::greater <int> ()
#define int long long
#define inf 1000000000000000001
#define BASE 29 // hashings mod, can be rand'd
#define mod 1000000007
#define pi 3.1415926535897
#define pii pair <int, int>
#define fii first
#define see second

typedef long long ll;
typedef long double ld;
using namespace std;

int n, m;
int ans=1;

// functions
int powmod(int a, int b){
	if(b==0){
		return 1;
	}
	int ret=powmod(a, b/2)%mod;
	if(b%2==0){
		return (ret*ret)%mod;
	}
	return (((ret*ret)%mod)*a)%mod;
}

void input(){
	cin >> n >> m;
	return;
}

void solve(){
	cout << powmod(powmod(2, m)-1, n);
	return;
}

void output(){
	return;
}

signed main(){
/*
//  REMEMBER TO TURN OFF IFDEF IN PROBLEMS WITH FILE I/O
*/
//#ifdef sheeep
//	freopen("forces.inp", "r", stdin);
//	freopen("forces.out", "w", stdout);
//#endif
	ios_base::sync_with_stdio(false);
//	int t;
//	cin >> t;
//	for(int i=1; i<=t; i++){
		input();
		solve();
		output();
//	}
	return 0;
}
// Author: NamSPro
