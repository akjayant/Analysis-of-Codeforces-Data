#include <bits/stdc++.h>
using namespace std;
long long t, n, m, p[100005], q[100005], pp, pq, npp, npq;
int main (){
ios::sync_with_stdio(0);
cin.tie(0); cout.tie(0);
cin >> t;
while (t--){
	cin >> n; npp=pp=0;
	for (int i=0; i<n; i++){
		cin >> p[i];
		if (p[i]%2) npp++;
		else pp++;
	}
	cin >> m; npq=pq=0;
	for (int i=0; i<m; i++){
		cin >> q[i];
		if (q[i]%2) npq++;
		else pq++;
	}
	cout << npq*npp + pp*pq << endl;
}

return 0;
}

