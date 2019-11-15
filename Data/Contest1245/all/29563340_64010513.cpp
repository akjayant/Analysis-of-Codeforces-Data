#include<bits/stdc++.h>
using namespace std; 
typedef long long ll;
#define pb push_back
#define fi first
#define se second
typedef long double ld;
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t; 
	cin>>t; 
	while(t--){
		int n; 
		cin>>n; 
		int a,b,c; 
		cin>>a>>b>>c;
		// a = R
		// b = P
		// c = S
		string s; 
		cin>>s; 
		string ans = "";
		int cnt = 0;
		for(int i=0;i<n;i++)ans+='A';
		for(int i=0;i<n;i++){
			if(s[i]=='R'){
				if(b){
					cnt++;
					b--;
					ans[i] = 'P';
				}
			}
			if(s[i]=='P'){
				if(c){
					cnt++;
					c--;
					ans[i] = 'S';
				}
			}
			if(s[i]=='S'){
				if(a){
					cnt++;
					a--;
					ans[i] = 'R';
				}
			}
		}
		if(cnt>=(n+1)/2){
			cout<<"YES\n";
			for(int i=0;i<n;i++){
				if(ans[i]=='A'){
					if(a){
						ans[i] = 'R';
						a--;
					}
					else if(b){
						ans[i] = 'P';
						b--;
					}
					else if(c){
						ans[i] = 'S';
						c--;
					}
				}
			}
			cout<<ans<<endl;
		}
		else{
			cout<<"NO\n";
		}
	}
	return 0;
}
