#include <bits/stdc++.h>
#define ll long long
#define MOD 1000000007

using namespace std;

ll power(ll a, ll b){
    if(b==0) return 1LL;
    ll ans = power(a,b/2);
    if(b%2==0) return (ans*ans)%MOD;
    else return ((a*ans)%MOD * ans)%MOD;
}

int main(){
	
	//fastio
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n,m;
    cin>>n>>m;
    cout<<(power(power(2,m)-1+MOD, n))<<endl;

}