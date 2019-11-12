#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double
#define mod 1000000007
#define F first
#define S second
#define FIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

int main(){
	FIO

    ll t;
    cin >> t;
    while(t--){
        ll a,b,c;
        cin >> a >> b >> c;
        ll ans = min(b,c/2)*3;
        b-=min(b,c/2);
        ans+=(min(a,b/2)*3);
        cout << ans << endl;
    }
    
	return 0;
}





