#include<iostream>
#include<algorithm>
using namespace std;
const long long mx=1e9;
const long long mod=1e9+7;
const long long maxn=2e5+10;
int gcd(int x,int y){
	return y==0?x:gcd(y,x%y);
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	int t;
	cin>>t;
	while(t--){
		int n,a,b,c;
		string s;
		char ans[201]={};
		cin>>n>>a>>b>>c>>s;
		int cnt=0;
		for(int i=0;i<n;i++){
			if(s[i]=='R'){
				if(b>0){
					b--;
					ans[i]='P';
					cnt++;
				}
				
			}else if(s[i]=='P'){
				if(c>0){
					c--;
					ans[i]='S';
					cnt++;
				}
			}else{
				if(a>0){
					a--;
					ans[i]='R';
					cnt++;
				}
			}
		}
		if(cnt*2<n){
			cout<<"NO\n";
			continue;
		}
		cout<<"YES\n";
		for(int i=0;i<n;i++)
			if(ans[i]!=0){
				cout<<ans[i];
			}else if(a>0){
				a--;
				ans[i]='R';
				cout<<ans[i];
			}else if(b>0){
				b--;
				ans[i]='P';
				cout<<ans[i];
			}else if(c>0){
				c--;
				ans[i]='S';
				cout<<ans[i];
			}
		cout<<endl;
	}
	return 0;
}