#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int q,r;
	cin >> q;
	for(r=0;r<q;r++){
		int a,b,c,d,k,i,j,memo;
		bool ans=false;
		cin >> a >> b >> c >> d >> k;
		for(i=0;i<=k;i++){
			j=k-i;
			if(c*i>=a&&d*j>=b){
				ans=true;
				break;
			}
		}
		if(!ans) cout << "-1" << endl;
		else cout << i << " " << j << endl;
	}
	return 0;
}