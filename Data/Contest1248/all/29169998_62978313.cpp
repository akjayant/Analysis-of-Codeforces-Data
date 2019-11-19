/* ashwani_er */

#include <bits/stdc++.h>

using namespace std;

#define int long long

signed main() {
	ios_base :: sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin>>t;
	
	while(t--)
	{
		int n;
		cin>>n;
		int ne=0,no=0;
		for(int i=0;i<n;i++){
			int x;
			cin>>x;
			if(x%2==0)  ne++;
			else        no++;
		}
		int m;
		cin>>m;
		int me=0,mo=0;
		for(int i=0;i<m;i++){
			int x;
			cin>>x;
			
			if(x%2==0) me++;
			else  mo++;
		}
		
		int ans=me*ne + mo*no;
		cout<<ans<<endl;
	}
	
}
