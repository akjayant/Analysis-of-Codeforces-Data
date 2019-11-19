#include <bits/stdc++.h>
#define INF 1e9+7
#define LINf 1e18+7
#define fr first 
#define sc second
#define ll long long
#define pb push_back
#define pii pair<int,int>

using namespace std;
int n, a[100005];

int main(){
	ios_base::sync_with_stdio(), cin.tie() , cout.tie();
	cin >> n;
	for(int i = 1; i <= n ; i++){
		cin >> a[i];
	}
	sort(a+1,a+n+1);
	int l = 1 , r = n;
	ll X = 0, Y = 0;
	while(l <= r){
		X += a[r];
		r--;
		if(r >= l){
			Y += a[l];
			l++;
		}
	}
	cout << X*X + Y*Y << '\n';
}