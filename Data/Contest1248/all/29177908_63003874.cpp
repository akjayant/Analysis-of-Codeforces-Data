#include<bits/stdc++.h>
using namespace std;
const int maxn = 505+5;
const int inf = 1e9;

int a[maxn],b[2*maxn];

int n;

int solve(){
	memset(b, 0 ,sizeof b);
	int minn = inf;
	int cnt = 0;
	for(int i = 1 ; i <= n ; i++){
		cnt += a[i];
		minn = min(minn,cnt);
		b[cnt + maxn]++;
	}
	return b[maxn+minn];
}

int main(){
	cin >> n;
	char c;
	int check = 0;
	for(int i = 1 ; i <= n ; i++){
		cin >> c;
		a[i] = (c == '(' ? 1 : -1);
		check += a[i];
	}
	if(check != 0){
		cout << "0\n1 1\n";
		return 0;
	}
	int ans = 0,ansl,ansr;
	for(int i = 1 ; i <= n ; i++){
		for(int j = i + 1 ; j <= n ; j++){

			swap(a[i],a[j]);
			int res = solve();
			if(res > ans){
				ans = res;
				ansl = i;
				ansr = j;
			}
			swap(a[i],a[j]);
		}
	}

	cout << ans << endl << ansl << " " <<ansr << endl;
}
