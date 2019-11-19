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

main(){
	int T;
	cin>>T;
	while( T-- ) {
		int a,b,c,d,k;
		cin>>a>>b>>c>>d>>k;
		int ans1,ans2;
		if(a%c==0) {
			ans1 = a/c;
		}
		else
			ans1 = a/c+1;
		if(b%d == 0) {
			ans2 = b/d;
		}
		else
			ans2 = b/d+1;
		if(ans1+ans2 >k) {
			cout<<-1<<"\n";
		}
		else
			cout<<ans1<<" "<<ans2<<"\n"; 
		
	}
	
}

