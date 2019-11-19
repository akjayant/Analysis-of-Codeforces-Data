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

int n,m,a,b,c,d,q;
vi V;

int R(int l, int p){
	return rand()%(p-l+1)+l;
}

void wczytaj(){
	cin>>a>>b>>c>>d>>q;
	int w1=1,w2=1;
	w1+=a/c;
	w2+=b/d;
	if (a%c==0)w1--;
	if (b%d==0)w2--;
	if (w1+w2>q)
		cout<<-1<<'\n';
	else
		cout<<w1<<' '<<w2<<'\n';
}

void solve(){

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
