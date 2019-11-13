#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(v) v.begin(), v.end()
int main(){
	int t; cin>>t;
	while(t--){
		int n; cin>>n;
		int a[1005];
		memset(a, 0, sizeof(a));
		for(int i=0; i<n; i++){
			int x; cin>>x;
			a[x]++;
		}
		for(int i=1000-1; i>=0; i--){
			a[i]=a[i+1]+a[i];
		}
		int i;
		for(i=0; i<=1000; i++){
			
			if(a[i]<i) break;
		}
		cout<<i-1<<endl;
	}
	return 0;
}