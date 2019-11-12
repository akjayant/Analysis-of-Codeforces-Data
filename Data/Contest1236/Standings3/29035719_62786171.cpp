#include <bits/stdc++.h>
#define forn(i,n) for(int i=0; i<n; i++)
#define pb push_back
#define ll long long int
#define mp make_pair
#define sz(arr) (ll)arr.size()
#define MOD 1000000007

using namespace std;

ll power(ll a,ll b){
	if (b==0) return 1;
	else if (b%2==0) return power((a*a)%MOD,b/2);
	else return (a*power((a*a)%MOD,b/2))%MOD;
}

int main(){
	ll a,b;
	cin>>a>>b;
	ll hold=power(2,b)-1;
	if (hold<0) hold+=MOD;
	hold=power(hold,a);
	cout<<hold;
}
