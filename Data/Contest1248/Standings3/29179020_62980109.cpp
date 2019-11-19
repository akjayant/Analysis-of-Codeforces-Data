#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int q,r;
	cin >> q;
	for(r=0;r<q;r++){
		int n,m,i;
		long long a1=0,a2=0,a3=0,a4=0;
		long long c;
		cin >> n;
		for(i=0;i<n;i++){
			cin >> c;
			if(abs(c)%2==0) a1++;
			else a2++;
		}
		cin >> m;
		for(i=0;i<m;i++){
			cin >> c;
			if(abs(c)%2==0) a3++;
			else a4++;
		}
		cout << a1*a3+a2*a4 << endl;
	}
	return 0;
}