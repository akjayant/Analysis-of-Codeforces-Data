#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
	int T;
	cin >> T;
	while(T--){
		int n,m;
		ll x=0,y=0,p=0,q=0;
		cin >> n;
		int a[n];
		for(int i=0;i<n;i++){
			cin >> a[i];
			if(a[i]%2)
				x++;
			else
				y++;
		}
		cin >> m;
		int b[m];
		for(int i=0;i<m;i++){
			cin >> b[i];
			if(b[i]%2)
				p++;
			else
				q++;
		}
		cout << (x*p)+(y*q) << endl;
	}
}