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
			ll len=0,pos1=-1,pos2=-1;
			rep(i,0,n){
				if(s[i]==t[i])len++;
				if(s[i]!=t[i]){
					if(pos1!=-1)pos2=i;
					else pos1=i;
				}
			}
			// telll(ok,pos1,pos2);
			if(len!=(n-2))ok=0;
			else{
				if(s[pos1]!=s[pos2])ok=0;
				else if(t[pos1]!=t[pos2])ok=0;
			}
			if(ok)cout<<"Yes\n";
			else cout<<"No\n";
		}
	}
	return 0;
}

