#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int r,q;
	//q=1;
	cin >> q;
	for(r=0;r<q;r++){
		int a,b,c,ans=0,i,j;
		cin >> a >> b >> c;
		for(i=0;i<=100;i++){
			for(j=0;j<=100;j++){
				if(i<=a&&2*i+j<=b&&2*j<=c){
					ans=max(ans,3*i+3*j);
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}