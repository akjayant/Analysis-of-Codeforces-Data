#include <bits/stdc++.h>
using namespace std;
string s, t;
long long q, n, ok, poz1, poz2;
int main (){
ios::sync_with_stdio(0);
cin.tie(0); cout.tie(0);
cin >> q;
while (q--){
	cin >> n >> s >> t; ok=0;
	for (int i=0; i<n; i++){
		if (s[i]!=t[i]){
			ok++;
			if (ok==1) poz1=i;
			else poz2=i;
		}
	} 
	if (ok==2 and s[poz1]==s[poz2] and t[poz2]==t[poz1]) 
		 cout << "Yes\n";
	else cout << "No\n";
}
return 0;
}

