#include <bits/stdc++.h>
#define ll long long
#define ld long double
#pragma 03
using namespace std;
int main(){
	int t, n;
	cin >> t;
	for (int i = 0; i<t; i++){
		cin >> n;
		int a[n+2], occr[n+2] = {0}, bigger[n+2];
		for (int j = 0; j<n; j++) cin >> a[j];
		sort(a, a+n);
		bool solved = false;
		bigger[n+1] = 0;
		for (int j = 0; j<n; j++) occr[a[j]]++;
		for (int j = n; j>=0; j--) bigger[j] = bigger[j+1] + occr[j];
		for (int j = n; j>=0; j--){
			if (bigger[j] >= j && solved == false){
				solved = true;
				cout << j << endl;
			}
		}
	}
	return 0;
}
 
