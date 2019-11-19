#include<bits/stdc++.h>
using namespace std;

#define int long long
#define MAXN 2000005

int n, k, a[MAXN];
int l,r;

void qwqr() {
	while(a[r] == a[r-1])	
		r --;
}

void qwql() {
	while(a[l] == a[l+1])	
		l ++;
}

signed main()
{
	cin >> n >> k;
	for(int i = 1; i <= n; i ++) 
		cin >> a[i];
	l = 1;
	r = n;
	sort(a + 1, a + 1 + n);
	qwql(); 
	qwqr();
	
	while(l < r) {
		if(l >= n - r + 1) {
			int t = (a[r]-a[r-1])*(n+1-r);
			if(k < t) {
				int ans = a[r]-k/(n-r+1)-a[l];
				cout<<ans;
				return 0;
			}
			r --;
			k -= t;
		} else {
			int t = (l)*(a[l+1]-a[l]);
			if(k < t) {
				int ans = a[r]-k/l-a[l];
				cout<<ans;
				return 0;
			}
			k -= t;
			l ++;
			qwql();
		}
	}
	cout<<0;
    return 0;
}