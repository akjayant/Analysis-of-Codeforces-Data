#include<bits/stdc++.h>
using namespace std;
#define endl '\n'

int main(){
	ios_base::sync_with_stdio(0);cin.tie(NULL);
	int t,n,cont,ans,i,j;
	cin>>t;
	while(t--){
		cin>>n;
		vector<int> V(n);
		for(i=0; i<n; i++){ cin>>V[i]; }
		for(i=n; i>=1; i--){
			cont = 0;
			for(j=0; j<n; j++){
				if(V[j] >= i)
				cont++;
			}
			if(cont >= i){
				ans = i;
				break;
			}
		}
		cout<<ans<<endl;
	}
}