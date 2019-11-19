#include<bits/stdc++.h>
#define ll long long 
#define ld long double
#define X first
#define Y second
#define pb push_back
#define max_el(x) max_element(x.begin(),x.end())-x.begin()
#define min_el(x) min_element(x.begin(),x.end())-x.begin()
#define mp make_pair
#define endl '\n'
#define fastread ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
// DONT USE MEMSET, USE VECTORS

void solve(){
	int n;
	cin>>n;
	vector<int> a(n);
	int ecnt = 0;
	int ocnt = 0;
	for(int i=0;i<n;i++){
		cin>>a[i];
		ecnt += (a[i]%2==0);
		ocnt += (a[i]%2==1);
	}
	int m;
	cin>>m;
	vector<int> b(m);
	ll ans = 0;
	for(int i=0;i<m;i++){
		cin>>b[i];
		if(b[i]%2==0){
			ans += ecnt;
		}
		else{
			ans += ocnt;
		}
	}

	cout<<ans<<endl;
	

}

int main(){
	fastread;
	int t;
	cin>>t;
	while(t--){
		solve();
	}		
}
