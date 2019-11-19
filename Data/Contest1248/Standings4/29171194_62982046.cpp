#include<iostream>
using namespace std;
typedef long long int ll;
int main(){
	//freopen("in","r",stdin);
	//freopen("out","w",stdout);
	ll n,m,T;
	cin>>T;
	while(T--){
		cin>>n;
		ll tmp;
		ll odd1=0,odd2=0,even1=0,even2=0;
		for(int i=0;i<n;i++){
			scanf("%lld",&tmp);
			if(tmp%2==0)even1++;
			else odd1++;
		}
		cin>>m;
		for(int i=0;i<m;i++){
			scanf("%lld",&tmp);
			if(tmp%2==0)even2++;
			else odd2++;
		}
		cout<<even1*even2+odd1*odd2<<endl;
	}
	return 0;
}
