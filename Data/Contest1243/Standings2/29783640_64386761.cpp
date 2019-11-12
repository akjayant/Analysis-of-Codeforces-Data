#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pll;
typedef pair<int,int> pii;
#define fastio() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define pb push_back
#define F first
#define S second
//cout<<fixed<<setprecision(11);
const string nl="\n";
const ll MOD=1000000007;
const ll ARR_MAX = 1e5+1;

void solve(){
	int n;cin>>n;
	string s,t;
	cin>>t>>s;
	vector<pii> swaps;
	bool f=0;
	for(int i=0;i<n;i++){
		if(s[i]==t[i]){
			continue;
		}
		bool flag=0;
		for(int j=i+1;j<n;j++){
			if(s[j]!=t[j] && t[j]==s[i]){
				swaps.pb({j,j});
				char temp=t[j];
				t[j]=s[j];
				s[j]=temp;
			}
			if(s[j]!=t[j] && s[i]==s[j]){
				swaps.pb({i,j});
				char temp=t[i];
				t[i]=s[j];
				s[j]=temp;
				flag=1;
				break;
			}
		}
		if(flag==0){
			f=1;
			break;
		}
	}
	if(f==0){
		cout<<"Yes"<<nl;
		// cout<<s<<nl<<t<<nl;
		cout<<swaps.size()<<nl;
		for(int i=0;i<swaps.size();i++){
			cout<<swaps[i].F+1<<" "<<swaps[i].S+1<<nl;
		}
	}
	else{
		cout<<"No"<<nl;
	}
}

int main(){
    fastio();
    int t=1;
    cin>>t;
    while(t--){
    	solve();
    }
    return 0;
}