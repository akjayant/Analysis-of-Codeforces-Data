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
const int maxn = 1e6; 

main(){IOS
	int n,p,w,d;
	cin>>n>>p>>w>>d;
	int a,b,c;
	for(int i=0;i<=maxn;i++) {
		if(i*d > p) break;
		else {
			if((p-i*d)%w==0) {
				a = (p-i*d)/w;
				b = i;
				break;
			}
		}
	}
	if(( n - a - b < 0)){
		cout<<-1;
	}
	else{
		cout<<a<<" "<<b<<" "<<n-a-b<<"\n";
	}
}

