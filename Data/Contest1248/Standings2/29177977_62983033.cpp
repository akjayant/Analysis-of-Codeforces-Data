#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e5+10;
int arr[maxn];
int main(){
	ios::sync_with_stdio(0);
	int n;
	cin>>n;
	for(int i=0;i<n;i++)cin>>arr[i];
	sort(arr,arr+n);
	ll a1=0,a2=0;
	for(int i=0;i<n/2;i++){
		a1+=arr[i];
	}
	for(int i=n/2;i<n;i++){
		a2+=arr[i];
	}
	cout<<(a1*a1+a2*a2)<<endl;
}
//-3 -15 0 1 12 -15 19
//