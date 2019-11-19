#include <bits/stdc++.h>
using namespace std;
long long a, b, n, ans, cost[5][100005];
bool v[100005]; int bojemogzivota[100005];
vector<int> c[100005];
long long check(int c1, int c2, int c3, int start){
	for (int i=1; i<=n; i++) v[i]=0;
	long long sum=0;
	int boja[]={c1, c2, c3}; v[start]=1;
	for (int kl=0; kl<n; kl++){
		bojemogzivota[start]=boja[kl%3];
		sum+=cost[boja[kl%3]][start]; //cout << start << " " << sum << " " << cost[boja[kl%3]][start] << endl;
		for (int lim=0; lim<c[start].size(); lim++){
			if (!v[c[start][lim]]){
				start = c[start][lim];
				v[start]=1;
				break;
			}
		}
	} //cout << endl << endl;
	return sum;
}
int main (){
ios::sync_with_stdio(0);
cin.tie(0); cout.tie(0);
cin >> n;
for (int i=1; i<4; i++) for (int j=1; j<=n; j++) cin >> cost[i][j];
for (int i=1; i<n; i++){cin >> a >> b; c[a].push_back(b); c[b].push_back(a);} bool ok=1;
for (int i=1; i<=n; i++){
	if (c[i].size()>2) ok=0;
	if (c[i].size()==1) a=i;
} if (!ok){cout << "-1"; return 0;}
ans=12345678987654321;
ans=min(ans, check(1, 2, 3, a));
ans=min(ans, check(1, 3, 2, a));
ans=min(ans, check(2, 1, 3, a));
ans=min(ans, check(2, 3, 1, a));
ans=min(ans, check(3, 1, 2, a));
ans=min(ans, check(3, 2, 1, a));
cout << ans << endl;
if (ans == check(1, 2, 3, a)){
	check (1, 2, 3, a);
	for (int i=1; i<=n; i++)
	cout << bojemogzivota[i] << " ";
}
else if (ans == check(1, 3, 2, a)){
	check (1, 3, 2, a);
	for (int i=1; i<=n; i++)
	cout << bojemogzivota[i] << " ";
}
else if (ans == check(2, 1, 3, a)){
	check (2, 1, 3, a);
	for (int i=1; i<=n; i++)
	cout << bojemogzivota[i] << " ";
}
else if (ans == check(2, 3, 1, a)){
	check (2, 3, 1, a);
	for (int i=1; i<=n; i++)
	cout << bojemogzivota[i] << " ";
}
else if (ans == check(3, 1, 2, a)){
	check (3, 1, 2, a);
	for (int i=1; i<=n; i++)
	cout << bojemogzivota[i] << " ";
}
else {
	check (3, 2, 1, a);
	for (int i=1; i<=n; i++)
	cout << bojemogzivota[i] << " ";
}
return 0;
}

