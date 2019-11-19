#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define dbg(x) cout <<#x<<":"<<x<<endl;
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL)
#define pb push_back
#define eb emplace_back
#define f first
#define s second
#define mp make_pair
#define pii pair<int,int>
#define pll pair<ll,ll>
#define endl '\n'
#define mod 1000000007
#define int long long
signed main(){
	fast;
	int t,n,x;
	int e1,o1,e2,o2;
	cin>>t;
	while(t--){	
	e1=0;o1=0;o2=0;e2=0;
		cin>>n;
		for(int i=0;i<n;i++){
			cin>>x;
			if(x&1) o1++;
			else	e1++;
		}
		cin>>n;
		for(int i=0;i<n;i++){
			cin>>x;
			if(x&1) o2++;
			else	e2++;
		}
		cout<<o2*o1 + e1*e2<<endl;
	}
}
