#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define f first
#define sec second
typedef long long ll;

int main(){
	int t;
	cin>>t;
	while(t--){
		int n, arr[200009];
		cin>>n;
		for(int i = 1; i <= n; i++){
			cin>>arr[i];
		}
		sort(arr+1, arr+1+n);
		int ans = 1;
		for(int i = n; i >= 1; i--){
			ans = max(ans, min(arr[i], n - i + 1));
		}
		cout<<ans<<'\n';
	}
}