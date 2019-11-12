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

const int mod=1e9+7;
typedef long long ll;

inline int sum(int a, int b){
	if(a+b>=mod){
		return a+b-mod;
	}
	else if(a+b<0){
		return a+b+mod;
	}
	return a+b;
}

inline int mul(int a, int b){
	return (ll)a*(ll)b%mod;
}

int pot(int x, int base){
	int sol=1;
	int y=x;
	while(base>0){
		if(base & 1){
			sol=mul(sol, y);
		}
		y=mul(y, y);
		base>>=1;
	}
	return sol;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, m;
	cin >> n >> m;
	cout << pot(pot(2, m)-1, n) << '\n';
	return 0;
}