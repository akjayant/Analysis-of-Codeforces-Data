#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define vec vector
#define psb push_back
#define ppb pop_back
#define mkp make_pair
#define fst first
#define scd second
#define ins insert
#define psf push_front
#define ppf pop_front
using namespace std;
ll modExp(ll a, ll b, ll c) {
	a %= c;
	ll ans = 1;
	for(; b; b >>= 1) {
		if(b & 1){
			ans *= a;
			ans %= c;
		}
		a *= a;
		a %= c;
	}
	return ans;
}
int main() {
	ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	ll k,n;
	cin>>k;
	while(k--){
		cin>>n;
		string a,b;
		cin>>a>>b;
		ll i , ca[26]={0}, cb[26]={0};
		set<ll> sa[26], sb[26];
		for(i=0;i<n;i++){
			ca[a[i]-'a']++;
			cb[b[i]-'a']++;
			sa[a[i]-'a'].ins(i);
			sb[b[i]-'a'].ins(i);
		}
		for(i=0;i<26;i++){
			if((ca[i]+cb[i])&1)
				break;
		}
		if(i<26){
			cout<<"No\n";
			continue;
		}
		vec<pair<ll,ll> > ans;
		for(i=0;i<n;i++){
			sa[a[i]-'a'].erase(i);
			//sb[b[i]-'a'].erase(i);
			if(a[i]==b[i]) {
				sb[b[i]-'a'].erase(i);
				continue;
			}
			if(sa[a[i]-'a'].empty()){
				ll x = *sb[a[i]-'a'].begin();
				sa[a[x]-'a'].erase(x);
				sb[a[x]-'a'].ins(x);
				sb[b[x]-'a'].erase(x);
				sa[b[x]-'a'].ins(x);
				swap(a[x], b[x]);
				sa[a[x]-'a'].erase(x);
				sa[b[i]-'a'].ins(x);
				sb[b[i]-'a'].erase(i);
				sb[a[x]-'a'].ins(i);
				swap(a[x], b[i]);
				ans.psb({x,x});
				ans.psb({x,i});
			}
			else{
				ll x = *sa[a[i]-'a'].begin();
				sa[a[x]-'a'].erase(x);
				sa[b[i]-'a'].ins(x);
				sb[b[i]-'a'].erase(i);
				sb[a[x]-'a'].ins(i);
				swap(a[x], b[i]);
				ans.psb({x,i});
			}
			sb[b[i]-'a'].erase(i);
		}
		if(a!=b){
			cout<<"No\n";
			continue;
		}
		cout<<"Yes\n"<<(ll)ans.size()<<"\n";
		ll x=ans.size();
		for(i=0;i<x;i++){
			cout<<ans[i].fst+1<<" "<<ans[i].scd+1<<"\n";
		}
	}
	return 0;
}
