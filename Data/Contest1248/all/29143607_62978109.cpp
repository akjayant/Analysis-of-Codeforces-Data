#include <bits/stdc++.h>
#define INF 1e9+7
#define LINf 1e18+7
#define fr first 
#define sc second
#define ll long long
#define pb push_back
#define pii pair<int,int>

using namespace std;
int t, n, m, p;
void solve(){
	cin >> n;
	int par = 0 , imp = 0;
	ll rez = 0;
	for(int i = 1; i <= n ; i ++){
		cin >> p;
		if(p%2==0)par++;
		else imp ++;
	}
	cin >> m;
	for(int i = 1 ; i<= m ; i++){
		cin >> p;
		if(p%2 == 0){
			rez += par;
		}else{
			rez += imp;
		}
	}
	cout << rez << '\n';
	return ;
}
int main(){
	ios_base::sync_with_stdio(), cin.tie() , cout.tie();
	cin >> t;
	while(t--){
		solve();
	}
}