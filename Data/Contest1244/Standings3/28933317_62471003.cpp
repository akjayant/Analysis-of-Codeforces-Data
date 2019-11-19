#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int q,r;
	cin >> q;
	for(r=0;r<q;r++){
		int a,b,c,d,k,i,j,memo,n,l,r;
		char s[1005];
		cin >> n >> s;
		l=1e9+7; r=1e9+7;
		for(i=0;i<n;i++){
			if(s[i]=='1'){
				l=n-i;
				break;
			}
		}
		for(i=n-1;i>=0;i--){
			if(s[i]=='1'){
				r=i+1;
				break;
			}
		}
		if(l==1e9+7&&r==1e9+7) cout << n << endl;
		else cout << 2*max(l,r) << endl;
	}
	return 0;
}