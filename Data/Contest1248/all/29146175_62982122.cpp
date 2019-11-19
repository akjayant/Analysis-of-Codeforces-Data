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
using namespace std;
ll n,a[maxn];
main(){
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
    cout.tie(NULL);   
    cin >> n;
    ll S = 0;
    For(i,1,n){
    	cin >> a[i];
    	S += a[i];
	}
	sort(a+1,a+n+1);
	ll s = 0;
	For(i,1,n/2){
		s+=a[i];
	}
	cout << ((S-s)*(S-s) + s*s);
}
