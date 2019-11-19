#include<bits/stdc++.h>

#define ll long long
#define X first
#define Y second
#define MP make_pair
#define PB push_back

using namespace std;

ll n,k;
ll niz[100005];

int main () {
	
	cin>>n>>k;
	for(int i=0; i<n; i++){
		cin>>niz[i];
	}
	sort(niz,niz+n);
	ll mini=niz[0];
	ll maxi=niz[n-1];
	ll a=0;
	ll b=n-1;
	ll c=0;
	while(a<n && niz[a]==mini){
		a++;
	}
	while(b>=0 && niz[b]==maxi){
		b--;
		c++;
	}
	while(maxi>mini){
		if(c<a){
			if((maxi-niz[b])*c<=k){
				k-=(maxi-niz[b])*c;
				maxi=niz[b];
				while(b>=0 && niz[b]==maxi){
					b--;
					c++;
				}
			}
			else{
				cout<<maxi-mini-k/c;
				return 0;
			}
		}
		else{
			if((niz[a]-mini)*a<=k){
				k-=(niz[a]-mini)*a;
				mini=niz[a];
				while(a<n && niz[a]==mini){
					a++;
				}
			}
			else{
				cout<<maxi-mini-k/a;
				return 0;
			}
		}
	}
	cout<<0;
	
	return 0;
}
