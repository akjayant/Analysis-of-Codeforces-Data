#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll dp[32][3][3];
int l,r;
void solve(){
	cin >> l >> r;
	dp[31][2][2]=1;
	bool eq=true;
	for(int i=30; i>=0 ;i--){
		int lb=(l&(1<<i))!=0;
		int rb=(r&(1<<i))!=0;
		for(int u=0; u<3 ;u++) for(int v=0; v<3 ;v++) dp[i][u][v]=0;
		bool peq=eq;
		if(lb!=rb) eq=false;
		for(int j=0; j<2 ;j++){
			for(int k=0; k<2 ;k++){
				if(j&k) continue;
				for(int u=0; u<3 ;u++){
					for(int v=0; v<3 ;v++){
						int nu=1,nv=1;
						if(eq && (lb!=j || lb!=k)) continue;
						if(eq){
							dp[i][u][v]+=dp[i+1][u][v];continue;
						}
						bool umi=peq || u==0;
						bool umx=peq || u==2;
						bool vmi=peq || v==0;
						bool vmx=peq || v==2;
						if(umi && lb>j) continue;
						if(umx && rb<j) continue;
						if(vmi && lb>k) continue;
						if(vmx && rb<k) continue;
						if(umi && lb==j) nu=0;
						if(umx && rb==j) nu=2; 
						if(vmi && lb==k) nv=0;
						if(vmx && rb==k) nv=2;
						dp[i][nu][nv]+=dp[i+1][u][v];
					}
				}
			}
		}
		//for(int u=0; u<3 ;u++) for(int v=0; v<3 ;v++) cout << dp[i][u][v] << ' ';
		//cout << endl;
	}
	ll sum=0;
	for(int u=0; u<3 ;u++) for(int v=0; v<3 ;v++) sum+=dp[0][u][v];
	cout << sum << '\n';
}
int main(){
	ios::sync_with_stdio(false);
	int t;cin >> t;
	while(t--) solve();
}