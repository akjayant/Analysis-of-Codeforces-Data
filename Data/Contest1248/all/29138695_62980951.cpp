#include <bits/stdc++.h>
using namespace std;
#define int long long

const int MAXN = 1E5+2;

int n;
int a[MAXN];

signed main(){
	cin >>n;
	for(int i=1; i<= n; ++i) cin >> a[i];
	sort(a+1, a+n+1);
	int x=0, y=0;
	for(int i=1; i<= n; ++i){
		if(i<= n/2) x+= a[i];
		else y+= a[i];
	}
	cout << (x*x + y*y);
}
