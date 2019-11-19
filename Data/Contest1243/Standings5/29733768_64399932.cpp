#include <bits/stdc++.h> 
using namespace std;
#define pb push_back
#define vi vector<int>
#define vpi vector<pair<ll,ll> >
#define mp make_pair
#define F first
#define S second
#define ll long long int
#define mod 1000000007
#define wh(a) cerr<<#a<<"  is  "<<a<<endl;
#define MIN(a,b) ((a) < (b) ? (a) : (b))
#define MAX(a,b) ((a) > (b) ? (a) : (b))

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	ll n,i,nn;
	cin>>n;
	if(n==2){
		cout<<2;
		return 0;
	}
//	nn=n;
//wh(nn);
	vector<ll> fac;
	for(i=2;i<=sqrt(n);++i){
		if(n%i==0){
//			wh(i);
			fac.pb(i);
			while(n%i==0){
				n=n/i;
//				wh(n;
			}
		}
	}
	if(n>2) fac.pb(n);
//	for(i=0;i<(int)fac.size();++i){
//		cout<<fac[i]<<' ';
//	}
//	cout<<endl;
	if((int)fac.size()==1){
		cout<<fac[0]<<endl;
	}
	else{
		cout<<1<<endl;
	}
	return 0;
}