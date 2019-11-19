#include<bits/stdc++.h>
#define ll long long int
#define pii pair<ll,ll>
#define mp make_pair
#define pb push_back
#define all(v) v.begin(),v.end()
#define ff first
#define ss second
#define M 500005
#define mod 1000000007
#define inf LLONG_MAX
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	ll t,n,m,q,i,j,k,x,y,z;
	string s;
	cin>>t;
	while(t--){
		cin>>n;
		cin>>s;
		x = 0;
		for(i=0;i<n;i++){
			if(s[i]=='1'){
				x = max(x,max(i+1,n-i));
//				cout<<"x"<<x<<"\n";
			}
		}
		cout<<max(n,2*x)<<"\n";
	}
}	

// Name - Hemant Chowdhury
// Arise, Awake And Stop Not Till The Goal Is Reached!
// If I fail,I will stand again;If I win,I will move farther





