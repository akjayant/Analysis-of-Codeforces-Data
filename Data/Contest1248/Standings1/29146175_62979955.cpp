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
ll t,n,m,pi,qi;
main(){
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
    cout.tie(NULL);   
    cin >> t;
    For(i,1,t){
    	ll chanP = 0;
    	ll leP = 0;
    	ll chanQ = 0;
    	ll leQ = 0;
    	cin >> n;
    	For(i,1,n){
    		cin >> pi;
    		if(pi%2==0){
    			chanP++;
			}	else	{
				leP++;
			}
		}
		cin >> m;
    	For(i,1,m){
    		cin >> pi;
    		if(pi%2==0){
    			chanQ++;
			}	else	{
				leQ++;
			}
		}
		cout << (chanP*chanQ + leP*leQ) << "\n";
	}
}
