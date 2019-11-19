#include<iostream>
#include<algorithm>
using namespace std;

typedef long long ll;
ll a[100005];


int main()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	ll sum1=0,sum2=0;
	for(int i=1,j=n;i<=j;i++,j--){
		sum1+=a[i];
		sum2+=a[j];
	}
	if(n%2==1){
		sum1-=a[n/2+1];
	}
	cout<<(sum1*sum1+sum2*sum2)<<endl;
	return 0;
}
