#include<bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	int t,a,b,c;
	cin >> t;
	while(t--){
		cin >> a >> b >> c;
		int maks1=min(a,b/2),maks2=min(b,c/2),ans=-1;
		for(int i=0;i<=maks1;i++){
			for(int j=0;j<=maks2;j++){
				if(i<=a && 2*i+j<=b && 2*j<=c)ans=max(ans,3*(i+j));
			}
		}
		cout << ans << endl;
	}
	return 0;
}


