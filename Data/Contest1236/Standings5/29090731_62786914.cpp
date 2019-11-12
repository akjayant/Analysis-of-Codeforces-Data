#include<bits/stdc++.h>
using namespace std;
#define endl '\n'

int main(){
	ios_base::sync_with_stdio(0);cin.tie(NULL);
	int t,a,b,c,k,ans,i,j;
	cin>>t;
	while(t--){
		cin>>a>>b>>c;
		ans = 0;
		for(i=0; i<=b && (2*i)<=c; i++){
			j = min((b-i)/2, a);
			k = 3*i + 3*j;

			if(k > ans)
			ans = k;
		}
		cout<<ans<<endl;
	}
}