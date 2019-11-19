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
	int n;
	cin>>n;
	vector<ll> v(n);
	for(int i=0;i<n;i++)
		cin>>v[i];
	sort(v.begin(),v.end());
	ll x1=0,x2=0;
	for(int i=0;i<n/2;i++)
		x1+=v[i];
	for(int i=n/2;i<n;i++)
		x2+=v[i];
	cout<< x1*x1 + x2*x2;
}
