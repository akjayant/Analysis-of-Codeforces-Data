#include <bits/stdc++.h>
using namespace std;
long long t, n, a1, a2;
string s;
int main (){
ios::sync_with_stdio(0);
cin.tie(0); cout.tie(0);
cin >> t;
for (int i=0; i<t; i++){
	cin >> n >> s; a1=a2=0;
	for (int i=0; i<n and s[i]=='0'; i++) a1++;
	for (int i=n-1; i>=0 and s[i]=='0'; i--) a2++;
	if (a1==n) cout << n;
	else cout << 2*(n - min(a1, a2));
	cout << endl;
}
return 0;
}

