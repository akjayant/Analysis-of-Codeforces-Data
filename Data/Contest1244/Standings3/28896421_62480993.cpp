#include <bits/stdc++.h>
using namespace std;
#define int long long

int gcd(int u, int v){
	return (v==0? u : gcd(v, u%v));
}

int n, p, w, d;


signed main(){
	cin >> n >> p >> w >> d;
	int g = gcd(w, d);
	if(p%g != 0){
		cout << "-1";
		return 0;
	}
	for(int y= 0; y < w; ++y){
		if(p - y*d >= 0 && (p-y*d)%w==0){
			int k = min(((n-y)-(p-y*d)/w)/(w-d), (p-y*d)/(w*d));
			int x = (p-y*d)/w - d*k;
			int z = n-x-(y+k*w);
			if(x >=0 && (y+k*w)>=0 && z>=0){
				cout << x << " " << y+k*w << " " << z << "\n";
				return 0;
			}
		}
	}
	cout << "-1";
	return 0;
}
