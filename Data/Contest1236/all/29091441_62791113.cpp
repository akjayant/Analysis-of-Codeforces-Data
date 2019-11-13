#include <bits/stdc++.h>
#define pp push_back
using namespace std;
typedef long long ll;

const ll P = 1000000007;
ll n,m;

ll power(ll a, ll b){
	vector<ll> p;
	p.pp(a);
	for(ll i=b/2; i; i/=2){
		p.pp((p.back()*p.back())%P);
	}
	ll i=b, r=1;
	int cnt=0;
	while(i){
		if(i%2) r*=p[cnt];
		r%=P;
		i/=2;
		cnt++;
	}
	return r;
}

int main(){
	cin>>n>>m;
	cout<< power((power(2,m)+P-1)%P,n);
}