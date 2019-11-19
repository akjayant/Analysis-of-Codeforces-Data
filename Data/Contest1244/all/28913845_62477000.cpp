#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
ll gcd(ll a , ll b){
	if(b==0)return a;
	return gcd(b , a%b);
}
int main(){
	ll n,p,d,w;
	cin>>n>>p>>w>>d;
	if(p > w*n) cout<<"-1"<<endl;
	else{
		ll x = gcd(d , w);
		if(p % x !=0) cout<<"-1"<<endl;
		else{
			w = w/x;
			d = d/x;
			p = p/x;
			ll kali = p/w;	
			while((p-kali*w)%d!=0){
				kali--;
			}
			if(kali < 0 || (p-kali*w)/d < 0) cout<<"-1"<<endl;
			else cout<<kali<<" "<<(p-kali*w)/d<<" "<<n-kali-(p-kali*w)/d<<endl;
		}
	}	
}
