#include<iostream>
using namespace std;

typedef long long ll;

int main()
{
	ios::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		ll sum1=0,sum2=0;
		for(int i=1;i<=n;i++){
			int p;
			cin>>p;
			if(p%2==1){
				sum1++;
			}
			else {
				sum2++;
			}
		}
		int m;
		cin>>m;
		ll sum3=0,sum4=0;
		for(int i=1;i<=m;i++){
			int p;
			cin>>p;
			if(p%2==1){
				sum3++;
			}
			else {
				sum4++;
			}
		}
		cout<<(sum1*sum3+sum2*sum4)<<endl;
	}
	return 0;
}
