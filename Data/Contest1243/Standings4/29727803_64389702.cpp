#include <iostream>
#include <bits/stdc++.h>
#define forn(i,n)for(int i=0;i<n;i++)
#define forna(i,a,n)for(int i=a;i<n;i++)
#define pb push_back
#define mp make_pair
#define maap map<int,int>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define mod 1000000007
#define ff first
#define ss second
#define INF 1e11
#define MAX 10000000
typedef long long ll;
using namespace std;

int main()
{
	IOS
	ll n;
	cin>>n;
	vector <ll> fact;
	for(ll i=2;i*i<=n;i++){
		if(n%i==0) {fact.pb(i);fact.pb(n/i);}
	}
	if(fact.empty()){
		cout<<n<<endl;return(0);
	}
	if(fact.size()==1){
		cout<<fact[0];return(0);
	}
	ll ans=fact[0];
	forna(i,1,fact.size()){
		ans = __gcd(ans,fact[i]);
	}
	cout<<ans;
}


