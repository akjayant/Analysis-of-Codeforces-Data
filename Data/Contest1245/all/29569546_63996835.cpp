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
int t,a,b;
main(){
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
    cout.tie(NULL);   
    cin >> t;
    while(t--){
    	cin >> a >> b;
    	if(__gcd(a,b)==1){
    		cout << "Finite\n";
		}	else	{
			cout << "Infinite\n";
		}
	}
}
