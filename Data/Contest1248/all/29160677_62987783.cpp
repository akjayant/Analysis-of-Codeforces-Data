#include<bits/stdc++.h>
using namespace std;

int main(){
		int n;cin>>n;
		vector<long long int> A(n);
		for(int i=0;i<n;i++)	cin>>A[i];	
		sort(A.begin(),A.end());
		long long int ans=0,odd=0,even=0;
		int i=0;
		while(i<n/2){
			odd+= A[i];
			i++;}
		ans+=odd*odd;
		while(i<n){
			even+= A[i];
			i++;}
		ans+=even*even;
		cout<<ans<<endl;	
	return 0;
}