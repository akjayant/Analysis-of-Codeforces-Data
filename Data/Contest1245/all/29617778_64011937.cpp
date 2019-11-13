#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define mp make_pair
#define fi first
#define se second
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define pb push_back
#define pii pair<ll,ll>
int main(){
	io;
	int t;
	cin>>t;
	while(t--){
		int n,a,b,c;
		cin>>n>>a>>b>>c;
		string s;
		cin>>s;
		string ans;
		int cnt=0;
		int cnt1=0,cnt2=0,cnt3=0;
		for(int i=0;i<n;i++){
			if(s[i]=='R')
			cnt1++;
			if(s[i]=='P')
			cnt2++;
			if(s[i]=='S')
			cnt3++;
		}
		int t1=min(cnt1,b),t2=min(cnt2,c),t3=min(cnt3,a);
		b-=t1;c-=t2;a-=t3;
		if((t1+t2+t3)*2>=n){
			cout<<"YES"<<endl;
			string z;
			for(int i=0;i<n;i++){
				if(s[i]=='R'){
					if(t1){
						t1--;
						z+='P';
					}
					else{
						if(c){
							c--;z+='S';
						}
						else if(a){
							a--;z+='R';
						}
					}
				}
				if(s[i]=='P'){
					if(t2){
						t2--;
						z+='S';
					}
					else{
						if(a){
							a--;z+='R';
						}
						else if(b){
							b--;z+='P';
						}
					}
				}
				if(s[i]=='S'){
					if(t3){
						t3--;
						z+='R';
					}
					else{
						if(c){
							c--;z+='S';
						}
						else if(b){
							b--;z+='P';
						}
					}
				}
			}
			cout<<z<<endl;
		}
		else{
			cout<<"NO"<<endl;
		}
		
	}
	return 0;
}



















