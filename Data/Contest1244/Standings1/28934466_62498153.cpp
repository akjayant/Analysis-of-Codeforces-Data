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

ll n,m,a,b,c,q,p,w,d;
vi V;

int R(int l, int p){
	return rand()%(p-l+1)+l;
}

void wczytaj(){
	cin>>n>>p>>w>>d;
}

void solve(){
	ll maxi=p/w;
	maxi*=w;
	ll wyn=0;
	bool czy=0;
	for (int i=0; i<=(int)1e5; ++i){
		if (i)
			maxi-=w;
		if (maxi<0)
			break;
		ll zostalo=p-maxi;
		if (zostalo%d==0){
			czy=1;
			wyn=zostalo/d;
			break;
		}
	}
	if (czy==0 or wyn+(maxi/w)>n){
		cout<<-1<<'\n';
		return;
	}
	cout<<maxi/w<<' '<<wyn<<' '<<n-(maxi/w)-wyn<<'\n';
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
