#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define ff fi.fi
#define fs fi.se
typedef long long ll;

ll arr[100005];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
//	int z,x,c;
	int tc;
//	cin>>tc;
	
//	for(int t=1;t<=tc;t++){
		int z;
		cin>>z;
		for(int q=1;q<=z;q++)cin>>arr[q];
		
		sort(arr+1,arr+1+z);
		int patok=z/2;
		ll temp1=0,temp2=0;
		for(int q=1;q<=z;q++){
			if(q<=patok){
				temp1+=arr[q];
			}
			else temp2+=arr[q];
		}
		ll ans=temp1*temp1 + temp2*temp2;
		cout<<ans<<endl;
//	}
}