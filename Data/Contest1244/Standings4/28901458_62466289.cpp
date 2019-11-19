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
int a,b,c,d,k,q;
main(){
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
    cout.tie(NULL);   
    cin >> q;
    For(i,1,q){
    	cin >> a >> b >> c >> d >> k;
    	int n1 = (a-1)/c+1;
		int n2 = (b-1)/d+1;
		if(n1+n2>k){
			cout << -1 << "\n";
		}	else	{
			cout << n1 << " " << n2 << "\n";
		}
	}
}
