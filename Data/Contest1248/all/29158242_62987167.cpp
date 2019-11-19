#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--){
		ll int n,m,a,i,po=0,pe=0,qo=0,qe=0;
		cin>>n;
		for(i=0;i<n;i++){
			cin>>a;
			if(a & 1 == 1){
				po++;
			}
			else{
				pe++;
			}
		}
		cin>>m;
		for(i=0;i<m;i++){
			cin>>a;
			if(a & 1 == 1){
				qo++;
			}
			else{
				qe++;
			}
		}
		ll int ans = po*qo + pe*qe;
		cout<<ans<<endl;
	}
}