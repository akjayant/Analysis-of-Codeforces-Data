#include <bits/stdc++.h>
using namespace std;
long long n, p, d, w, x, y, z;
long long gcd(long long a, long long b){
	while(b){long long c=b; b=a%b; a=c;}
	return a;
}
int main (){
ios::sync_with_stdio(0);
cin.tie(0); cout.tie(0);
cin >> n >> p >> w >> d;
long long provjera=gcd(w,d);
if (p%provjera){cout << "-1"; return 0;}
p/=provjera; w/=provjera; d/=provjera;
for (int i=0; i<d and (p-i*w)>=0; i++){
	if (!((p-i*w)%d)){
		x = i;
		y = (p-i*w)/d;
		z = n-x-y;
		if (z>=0){cout << x << " " << y << " " << z; return 0;}
		int korekcija = (-z) / (w-d); if ((-z)%(w-d)) korekcija++;
		z = z + (w-d)*korekcija;
		x = x + d*korekcija;
		y = y - w*korekcija;
		if (x>=0 and y>=0 and z>=0){cout << x << " " << y << " " << z; return 0;}
		else {cout << "-1"; return 0;}
	}
}
cout << "-1"; return 0;
}

