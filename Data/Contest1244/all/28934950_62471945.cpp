#include <bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0);cin.tie(0);
#define int long long
#define X first
#define Y second
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define int long long
#define de(x,y) cout<<#x<<" "<<x<<y;
#define pray(a,i,n_thing) for(int x=i;x<=(i+n_thing);x++) cout<<#a<<"["<<x<<"] :"<<a[x]<<endl;
#define mem(aa,x) memset(aa,x,sizeof aa)
#define pb push_back
typedef long long ll;
typedef pair<int,int> ii;
const int maxn=4e5+5;
int arr[maxn];

main(){IOS
	int T;
	cin>>T;
	while( T-- ) {
		int n;
		cin>>n;
		for(int i=1;i<=n;i++) {
			char a;
			cin>>a;
			if(a=='0')	
				arr[i] = 0;
			else
				arr[i] = 1;
		} 
		int ans = n;
		for(int i=n;i>=1;i--) {
			if(arr[i] == 1) {
				ans = max(ans,i * 2);
				break;
			}
		}
		for(int i=1;i<=n;i++) {
			if(arr[i] == 1) {
				ans = max(ans,(n-i+1) * 2);
				break;
			}
		} 
		cout<<ans<<"\n";
	}
	
}

