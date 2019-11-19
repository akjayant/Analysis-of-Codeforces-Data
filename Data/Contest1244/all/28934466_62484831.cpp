#include<bits/stdc++.h>
#define pb push_back
#define pob pop_back
#define pf push_front
#define pof pop_front
#define nd second
#define st first
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
using vi=vector<int>;
using vl=vector<ll>;
using mii=map<int,int>;
using si=set<int,int>;
using vpi=vector<pii>;
using vpl=vector<pll>;

const int N=(int)1e0+5;

ll n,m,a,b,c,q,roz;
vi V;
vpl lic,zm1,zm2,xd;
ll k;

int R(int l, int p){
	return rand()%(p-l+1)+l;
}

void wczytaj(){
	cin>>n>>k;
	for (int i=0; i<n; ++i){
		cin>>a;
		V.pb(a);
	}
	sort(V.begin(),V.end());
	roz=V[n-1]-V[0];
	int ile=1,war=V[0];
	for (int i=1; i<n; ++i){
		if (V[i]==war)
			ile++;
		else{
			lic.pb({ile,war});
			ile=1;
			war=V[i];
		}
	}
	lic.pb({ile,war});
}

void solve(){
	int koszt=lic[0].st;
	for (int i=1; i<lic.size(); ++i){
		zm1.pb({koszt,lic[i].nd-lic[i-1].nd});
		koszt+=lic[i].st;
	}
	koszt=lic.back().st;
	for (int i=lic.size()-1; i; --i){
		zm2.pb({koszt,lic[i].nd-lic[i-1].nd});
		koszt+=lic[i-1].st;
	}
	zm2.pb({(ll)1e18,1});
	zm1.pb({(ll)1e18,1});
	for (auto i:zm1)
		xd.pb(i);
	for (auto i:zm2)
		xd.pb(i);
	sort(xd.begin(),xd.end());
	int wsk=0;
	while (roz>0 and k>=xd[wsk].st){
		ll maxi=k/xd[wsk].st;
		maxi=min(maxi,xd[wsk].nd);
		roz-=maxi;
		k-=maxi*xd[wsk].st;
		wsk++;
	}
	cout<<max(0LL,roz)<<'\n';
}

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int ilosc_przypadkow_testowych=1;
//	cin>>ilosc_przypadkow_testowych
	for (int i=1; i<=ilosc_przypadkow_testowych; ++i){
		wczytaj();
		solve();
	}
}
