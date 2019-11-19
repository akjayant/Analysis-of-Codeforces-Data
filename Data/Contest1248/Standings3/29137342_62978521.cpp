#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define pb push_back
#define int long long int
#define mod 1000000007
void fast(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}
main()
{
	fast();
	int t;
	cin>>t;
	while(t--){
		int n,x,o1=0,e1=0,o2=0,e2=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>x;
			if(x%2==0)e1++;
			else o1++;
		}
		int m;
		cin>>m;
		for(int i=1;i<=m;i++){
			cin>>x;
			if(x%2==0)e2++;
			else o2++;
		}
		int ans=o1*o2+e1*e2;
		cout<<ans<<endl;
	}
}