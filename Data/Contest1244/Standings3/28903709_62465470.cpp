#include <bits/stdc++.h>
using namespace std;
long long q, a, b, c, d, k;
int main (){
ios::sync_with_stdio(0);
cin.tie(0); cout.tie(0);
cin >> q;
for (int kl=0; kl<q; kl++){
	cin >> a >> b >> c >> d >> k;
	if ((a/c+(int)((a%c)?1:0) + b/d + (int)((b%d)?1:0))<=k) 
		cout << a/c + (int)((a%c)?1:0) << " " << b/d + (int)((b%d)?1:0);
	else cout << "-1";
	cout << endl;
}
return 0;
}

