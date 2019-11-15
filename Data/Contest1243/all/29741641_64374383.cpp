#include<bits/stdc++.h>
#pragma GCC optimize ("-ffloat-store")
#define ll long long
#define For(i,a,b) for(ll i=a;i<=b;i++)
#define maxn 100002
#define pb push_back
#define X first
#define Y second
#define mod 1000000007
#define base 17
//#define db(x) cerr << "[" << #x << ": " << (x) << "] ";
#define db(x) ;
using namespace std;
int n,t,a[10005];

main(){
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
    cout.tie(NULL);   
    cin >> t;
    while(t--){
    	cin >> n;
    	For(i,1,n){
    		cin >> a[i];
		}
		sort(a+1,a+n+1);
		int mi = 10000;
		int ans = 0;
		for(int i=n;i>=1;i--){
			mi = min(mi,a[i]);
			int num = n-i+1;
			ans = max(ans, min(mi,num));
		}
		cout << ans << "\n";
	}
}
