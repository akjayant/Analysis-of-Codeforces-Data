#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const double eps = 1e-6;
const int N = 1e5+7;
typedef long long ll;
const ll mod = 1e9+7;
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int t;
	cin>>t;
	while(t--){
		int n; cin>>n;
		int a,b,c; cin>>a>>b>>c;
		string s; cin>>s;
		char v[107];
		int cnt=0;
		int vis[107]={0};
		for(int i=0;i<s.size();i++){
			if(s[i]=='R'){
				if(b){
					cnt++;
					b--;
					v[i]='P';
					vis[i]=1;
				}
			}
			if(s[i]=='P'){
				if(c){
					cnt++;
					c--;
					v[i]='S';
					vis[i]=1;
				}
			}
			if(s[i]=='S'){
				if(a){
					cnt++;
					a--;
					v[i]='R';
					vis[i]=1;
				}
			}
		}
		if(cnt>=((n+1)/2)){
			cout<<"YES\n";
			for(int i=0;i<s.size();i++){
				if(!vis[i]){
					if(a){
						a--;
						v[i]='R';
					}else if(b){
						b--;
						v[i]='P';
					}else if(c){
						c--;
						v[i]='S';
					}
				}
			}
			for(int i=0;i<s.size();i++){
				cout<<v[i];
			}	cout<<"\n";
		}else{
			cout<<"NO\n";
		}
	}
	return 0;
} 