#include <bits/stdc++.h>
#define up(i,a,b) for(int (i) = (a);(i)<=(b);++(i))
#define down(i,b,a) for(int (i) = (b);i>=(a);--i)
#define debug(x) cerr << (x) << '\n';
#define bits(x,i) ((x >> i) & 1)
using namespace std;
const int N = 101;
const long long base = 1e9 + 7; 
long long n,m;
long long multi(long long n, long long m){
	long long ans = 1;
	up(i,0,29){
		if (bits(m, i)) ans = (ans * n) % base;
		n = (n * n) % base;
	}
	return ans;
}
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;
	long long ans = (multi(2, m) + base - 1) % base;
	ans = multi(ans, n);
	cout << ans;
}