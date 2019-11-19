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

int n,m,a,b,c,q;
vi V;
string A;

int R(int l, int p){
	return rand()%(p-l+1)+l;
}

void wczytaj(){
	cin>>n>>A;
}

void solve(){
	int wyn=n;
	for (int i=0; i<n; ++i){
		if (A[i]=='1'){
			wyn=max(wyn,max(i+1,n-i)*2);
		}
	}
	cout<<wyn<<'\n';
}

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int ilosc_przypadkow_testowych=1;
	cin>>ilosc_przypadkow_testowych;
	for (int i=1; i<=ilosc_przypadkow_testowych; ++i){
		wczytaj();
		solve();
	}
}
