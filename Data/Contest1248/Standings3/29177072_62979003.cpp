#include<bits/stdc++.h>
#define FIN freopen("./A.in","r",stdin)
using namespace std;
typedef long long ll;
const ll maxn(1e5+5);
ll T,n,oddn,oddm,even,evem,tmp;
int main(){
#ifndef ONLINE_JUDGE
	FIN;
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>T;
	for(int t=1;t<=T;t++){
		oddm=oddn=even=evem=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>tmp;
			if(tmp%2){
				oddn++;
			}else{
				even++;
			}
		}
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>tmp;
			if(tmp%2){
				oddm++;
			}else{
				evem++;
			}
		}
		cout<<oddm*oddn+even*evem<<"\n";
	}
}
