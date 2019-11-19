#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <cmath>
using namespace std;
typedef long long LL;

LL n,p,w,d,x,y;

void exgcd(LL a,LL b,LL &x,LL &y){
	if(!b){ x = 1; y = 0; return; }
	exgcd(b,a % b,x,y);
	LL tx = x;
	x = y;
	y = tx - a / b * x;
}

LL gcd(LL a,LL b){
	if(!b) return a;
	return gcd(b,a % b);
}

int main(){
	ios::sync_with_stdio(false);
	cin >> n >> p >> w >> d;
	exgcd(w,d,x,y);
	LL GCD = gcd(w,d);
	if(p % GCD != 0){
		cout << -1 << endl;
		return 0;
	}
	w /= GCD;
	d /= GCD;
	p /= GCD;
	
//	x *= p;
//	y *= p;
//	x = (x % d + d) % d;
//	y = (p - w * x) / d;
	
	x = (((x % d) * (p % d)) % d + d) % d;
	y = (p - w * x) / d;
	
	if(x + y <= n && x >= 0 && y >= 0){
		cout << x << ' ' << y << ' ' << n - x - y << endl;
		return 0;
	}
	y = (y % w + w) % w;
	x = (p - d * y) / w;
	if(x + y <= n && x >= 0 && y >= 0){
		cout << x << ' ' << y << ' ' << n - x - y << endl;
		return 0;
	}
	cout << -1 << endl;
	return 0;
}