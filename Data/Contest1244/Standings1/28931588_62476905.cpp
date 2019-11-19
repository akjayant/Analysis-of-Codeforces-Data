#include<bits/stdc++.h>

#define x first
#define y second

using namespace std;

typedef long long INT;

#define NN 100010

int a[NN];
int n;
INT k;
INT sum[NN];

int can(int L, int R) {
	int idl = upper_bound(a+1, a+n+1, L) - a; idl--;
	int idr = upper_bound(a+1, a+n+1, R) - a;
	return ((INT) L * idl - sum[idl] - (INT) R * (n - idr + 1) + (sum[n] - sum[idr-1])) <= k;
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("in.in","r",stdin);
	freopen("out.out","w",stdout);
#endif
	cin >> n >> k; 
	
	for(int i=1; i<=n; i++) {
		scanf("%d", a+i);
	}
	
	sort(a+1, a+n+1);
	for(int i=1; i<=n; i++) sum[i] = sum[i-1] + a[i];
	int st = -1, ed = 1000000001;
	
	while(st + 1 < ed) {
		int md = (st + ed) / 2;
		int flag = 0;
		for(int i=1; i<=n and !flag; i++) {
			if(can(a[i], a[i] + md)) flag = 1;
			if(can(a[i] - md, a[i])) flag = 1;
		}
		if(flag) ed = md;
		else st = md;
	}
	
	cout << ed << endl;
	return 0;
}

                           