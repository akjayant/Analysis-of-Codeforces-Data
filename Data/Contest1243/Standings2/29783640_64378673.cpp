#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pll;
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
	cin>>s>>t;
	int i1=-1,i2=-1;
	bool flag=0;
	for(int i=0;i<n;i++){
		if(s[i]!=t[i]){
			if(i1==-1) i1=i;
			else if(i2==-1) i2=i;
			else{
				flag=1;
				break;
			}
		}
	}
	if(i2==-1){
		flag=1;
	}
	if(flag==0 && s[i1]==s[i2] && t[i1]==t[i2]){
		cout<<"Yes"<<nl;
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