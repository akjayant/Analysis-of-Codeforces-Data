#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int r,q;
	q=1;
	//cin >> q;
	for(r=0;r<q;r++){
		int n,i,j;
		cin >> n;
		if(n%2==0){
			for(i=0;i<n;i++){
				for(j=0;j<n;j++){
					if(j%2==0){
						cout << n*j+i+1;
					} else {
						cout << n*(j+1)-i;
					}
					if(j!=n-1) cout << " ";
				}
				cout << endl;
			}
		} else {
			for(i=0;i<n;i++){
				for(j=0;j<n;j++){
					if(j%2==0){
						cout << n*j+i+1;
					} else {
						cout << n*(j+1)-i;
					}
					if(j!=n-1) cout << " ";
				}
				cout << endl;
			}
		}
	}
	return 0;
}