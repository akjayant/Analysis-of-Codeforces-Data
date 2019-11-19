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
int q,n;
string s;
main(){
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
    cout.tie(NULL);   
    cin >> q;
    For(i,1,q){
    	cin >> n;
    	cin >> s;    	
    	int ans = n;
    	for(int i=0;i<n;i++){
    		if(s[i]=='1'){
    			ans = max(ans, 2*max(i+1,n-i));
			}
		}
		cout << ans << "\n";
	}
}
