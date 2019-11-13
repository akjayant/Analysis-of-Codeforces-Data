#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf=1e6+69;
const ll infll=1e18+69;
const ll mod=1e9+7;
const ld pi=acos(-1.0L);
#define fio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define	ed return 0
#define hi hfvjidwkofiuhgaew
#define all(v) v.begin(), v.end()
int gcd(int a, int b){
	if(a<b) swap(a, b);
	if(b==0) return a;
	return gcd(b, a%b);
}
int main(){
	fio;
	int t; cin>>t;
	while(t--){
		int n; cin>>n;
		int a, b, c; cin>>a>>b>>c;
		string s; cin>>s;
		string ans=""; int cnt=0;
		for(int i=0; i<n; i++){
			char now=s[i];
			if(now=='R'){
				if(b>0){
					ans+='P'; b--;
					cnt++;
				}else{
					ans+='-';
				}
			}else if(now=='P'){
				if(c>0){
					ans+='S'; c--;
					cnt++;
				}else{
					ans+='-';
				}
			}else if(now=='S'){
				if(a>0){
					ans+='R'; a--;
					cnt++;
				}else{
					ans+='-';
				}
			}
		}
		if(cnt>=(n+1)/2){
			cout<<"YES\n";
			for(int i=0; i<n; i++){
				if(ans[i]=='-'){
					if(a>0){
						ans[i]='R'; a--;
					}else if(b>0){
						ans[i]='P'; b--;
					}else if(c>0){
						ans[i]='S'; c--;
					}
				}
			}
			cout<<ans<<endl;
		}else{
			cout<<"NO\n";
		}
	}
	ed;
}