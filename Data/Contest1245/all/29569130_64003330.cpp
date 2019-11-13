//amitgomi
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define fi first
#define se second
#define pb push_back
#define all(x) x.begin(),x.end()
#define mp(x,y) make_pair(x,y)
#define mod 1000000007
#define sc(x) scanf("%d", &x)
#define sl(x) scanf("%lld", &x)
 
///////////////////////////////////////////////////////////
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
// typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
// ordered_set st;
// st.order_of_key(l);
// double PI=3.1415926535897932384626;
// ll bin_expo(ll a,ll b, ll m){ ll res =1; a %= m; while(b!=0){ if(b%2==1) res = (res*a)%mod; a = (a*a)%mod; b = b/2; } return res; }
// ll gcd(ll a, ll b) { if (b == 0) return a; return gcd(b, a % b); } 
///////////////////////////////////////////////////////////////////////////////////////////////////


int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	int t;
	cin>>t;
	while(t--){
		int n,a,b,c;
		cin>>n>>a>>b>>c;
		string S;
		cin>>S;
		int r=0,p=0,s=0;
		for(int i=0;i<S.length();i++){
			if(S[i]=='P')
				p++;
			if(S[i]=='R')
				r++;
			if(S[i]=='S')
				s++;
		}
		int t = min(r,b)+min(p,c)+min(s,a);
		int w = n-(n/2);
		// cout<<t<<' '<<w<<endl;
		int a1 = a-min(s,a),b1 = b-min(r,b),c1 = c-min(p,c);
		a = a-a1;
		b = b-b1;
		c = c-c1;
		if(t>=w){
			cout<<"YES"<<endl;
			for(int i=0;i<n;i++){
				if(S[i]=='R'){
					if(b>0){
						cout<<"P";
						b--;
					}
					else if(a1>0){
						cout<<"R";
						a1--;
					}
					else if(b1>0){
						cout<<"P";
						b1--;
					}
					else{
						cout<<"S";
						c1--;
					}
				}
				if(S[i]=='P'){
					if(c>0){
						cout<<"S";
						c--;
					}
					else if(a1>0){
						cout<<"R";
						a1--;
					}
					else if(b1>0){
						cout<<"P";
						b1--;
					}
					else{
						cout<<"S";
						c1--;
					}
				}
				if(S[i]=='S'){
					if(a>0){
						cout<<"R";
						a--;
					}
					else if(a1>0){
						cout<<"R";
						a1--;
					}
					else if(b1>0){
						cout<<"P";
						b1--;
					}
					else{
						cout<<"S";
						c1--;
					}
				}
			}
			cout<<endl;
		}
		else
			cout<<"NO"<<endl;
	}
	return 0;
}

