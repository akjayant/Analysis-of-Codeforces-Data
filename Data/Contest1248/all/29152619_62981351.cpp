#include<bits/stdc++.h>
using namespace std;

#define N 200123
#define mod 1000000007

void solve(){
	int n, m, p, q;
	long long oddp = 0, oddq = 0, evenp = 0, evenq = 0;
	cin >> n;
	for(int i = 0 ; i < n ; ++i){
		cin >> p;
		if(p % 2) oddp++;
		else evenp++;
	}
	cin >> m;
	for(int i = 0; i < m; ++i){
		cin >> q;
		if(q % 2) oddq++;
		else evenq++;
	}
	cout << (oddp*oddq) + (evenp*evenq) << endl;
}

int main(){
    ios::sync_with_stdio(false);
	cin.tie(0);
    if(fopen("input.in", "r")){
        freopen("input.in", "r", stdin);
        freopen("output.out", "w", stdout);
    }
    int t;
    cin >> t;
    while(t--){
    	solve();
    }
    return 0;
}