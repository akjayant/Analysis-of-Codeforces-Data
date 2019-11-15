#include <bits/stdc++.h>
using namespace std;
int main(){
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
	int q;
	cin >> q;
	while(q--){
		int n;
		cin >> n;
		int a[n];
		for(int i=0;i<n;i++)
			cin >> a[i];
		sort(a,a+n);
		int m=0;
		for(int i=n-1;i>=0;i--){
			int k=min(a[i],n-i);
			m=max(m,k);
		}
		cout << m << endl;
	}
}