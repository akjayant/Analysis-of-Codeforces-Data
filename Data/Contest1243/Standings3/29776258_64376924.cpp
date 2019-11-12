#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int k;
	cin>>k;
	while(k--){
		int n;
		cin>>n;
		int a[n], count[1010] = {0};
		for(int i=0;i<n;i++){
			cin>>a[i];
			count[a[i]]++;
		}
		
		for(int i=1000;i>=0;i--){
			count[i] += count[i+1];
		}
		int ans = 0;
		for(int i=0;i<1010;i++){
			if(count[i]>=i){
				ans = i;
			}
		}
		// for(int i=0;i<10;i++){
		// 	cout<<count[i]<<" ";
		// }
		// cout<<count[4];
		cout<<ans<<endl;
	}
	return 0;
}