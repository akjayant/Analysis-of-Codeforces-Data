#include <bits/stdc++.h>
#define ll long long
#define md 1000000007
using namespace std;
int main(){
	ll n, m;
	cin >> n >> m;
	if(n>m)	
	  swap(n,m);
	ll d[m+2];
	d[1] = 2, d[2] = 4;
	for(int i=3;i<=m;i++)
		d[i] = (d[i-1] + d[i-2])%md;
	ll z = (d[m] + (d[n] - 2))%md;
	cout << z << endl;
	return 0;
}