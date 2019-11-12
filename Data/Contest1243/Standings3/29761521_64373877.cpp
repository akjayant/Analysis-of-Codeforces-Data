#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main() { 
    ios_base::sync_with_stdio(0); cin.tie(0);
    int T; cin>>T;
    int n,arr[1001],ans,vigo;
    while(T--){
    	cin>>n;
    	for(int i=1;i<=n;i++) cin>>arr[i];
    	sort(arr+1,arr+n+1,[&](int a, int b){
    		return a>b;
		});
		ans=0;
    	for(int i=1;i<=n;i++){
    		vigo=min(i,arr[i]);
    		ans=max(ans,vigo);
		}
		cout<<ans<<'\n';
	}
}