#include<bits/stdc++.h>
#include<ext/rope>
using namespace std;
using namespace __gnu_cxx;
#define fi first
#define se second
#define fastio ios_base::sync_with_stdio(false);cin.tie(0)
#define fopen freopen("input.txt", "r", stdin)
#define pb push_back
#define prec(a) cout<<fixed;cout.precision(a);
#define all(a) (a).begin(), (a).end()
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const ll INF = 9e18;
const int inf = 2e9;
template<class T>
void pr(T t) {cout << t << " ";}
template<class T, class ...Args>
void pr(T a, Args ...args) {cout << a << " ";pr(args...);}
template<class ...Args>
void prl(Args ...args) {pr(args...);cout << endl;}

int n;
string a, b;
int acnt[28],bcnt[28];
vector<pii> ans;
void sw(int x, int y){
	ans.pb({x,y});
	swap(a[x], b[y]);
}
void sw2(int x, int y){
	sw(y,y);
	sw(x,y);
}
int f(int t, int s, char v){
	if(t==1){
		for(int i=s;i<n;i++){
			if(a[i]==v) return i;
		}
		return 0;
	}
	for(int i=s;i<n;i++){
		if(b[i]==v) return i;
	}
	return 0;
}
int main(){
	fastio;
	int q;
	cin>>q;
	while(q--){
		ans.clear();
		cin>>n;
		for(int i=0;i<27;i++){
			acnt[i]=bcnt[i]=0;
		}
		cin>>a;
		cin>>b;
		for(int i=0;i<n;i++){
			acnt[a[i]-'a']++;
			bcnt[b[i]-'a']++;
		}
		int flag=0;
		for(int i=0;i<26;i++){
			if((acnt[i]+bcnt[i])%2!=0){
				flag=1;break;
			}
		}
		if(flag){
			cout<<"No\n";
			continue;
		}
		for(int i=0;i<n-1;i++){
			if(a[i]==b[i]) continue;
			if(f(2,i+1,b[i])){
				int cur = f(2,i+1,b[i]);
				sw(i,cur);
			}
			else {
				int cur = f(1,i+1,b[i]);
				sw2(i,cur);
			}
		}
		if(ans.size()>2*n) {
			cout<<"No\n";
		}
		else {
			cout<<"Yes\n";
			cout<<ans.size()<<"\n";
			for(auto i:ans){
				cout<<i.fi+1<<" "<<i.se+1<<"\n";
			}
		}
	}
}