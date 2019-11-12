#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define mk make_pair
#define fi first
#define se second
#define vll vector<ll>
#define pii pair<ll,ll>
#define vvll vector< vector<ll> >
#define pb push_back
#define sz(v) (v).size()
#define inf 1e18
#define md 1000000007
#define all(v) (v).begin(),(v).end()
#define rep(i,a,b) for(ll i=a;i<b;++i)
#define tel(a){cout<<a<<"\n";}
#define tell(a,b){cout<<a<<" | "<<b<<"\n";}
#define telll(a,b,c){cout<<a<<" | "<<b<<" | "<<c<<"\n";}
#define teln(v,n){cout<<"v- ";rep(i,0,n)cout<<v[i]<<" ";cout<<"\n";}
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
#define M 1000010

int main(){
	IOS;
	int t;cin>>t;
	while(t--){
		ll n;cin>>n;
		string s,t;cin>>s>>t;
		bool ok=1;
		if(s==t)cout<<"Yes\n";
		else{
			ll a[26];rep(i,0,26)a[i]=0;
			rep(i,0,n)a[s[i]-'a']++;
			rep(i,0,n)a[t[i]-'a']++;
			rep(i,0,26)if(a[i]&1)ok=0;
			vector<pii>v;
			rep(i,0,n){
				bool f=0;
				if(s[i]==t[i])continue;
				rep(j,i+1,n){
					if(s[i]==s[j]){
						v.pb({j+1,i+1});
						swap(t[i],s[j]);
						f=1;
						break;
					}
				}
				if(!f){
					rep(j,i+1,n){
						if(s[i]==t[j]){
							v.pb({j+1,j+1});
							swap(s[j],t[j]);
							v.pb({j+1,i+1});
							swap(s[j],t[i]);
							break;
						}
					}
				}
			}
			if(s!=t)ok=0;
			if(!ok)cout<<"No\n";
			else{
				cout<<"Yes\n";
				cout<<sz(v)<<"\n";
				rep(i,0,sz(v))cout<<v[i].fi<<" "<<v[i].se<<"\n";
			}
		}
	}
	return 0;
}

