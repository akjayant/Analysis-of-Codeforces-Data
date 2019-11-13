#include<bits/stdc++.h>
using namespace std;
#define int long long
int M=1e9+7;



int32_t main(){
	int n;cin>>n;
	int a[n][n];
	int k=1;
	int f=0;
	for(int i=0;i<n;i++){
		if(f==0){
			for(int j=0;j<n;j++){
				a[j][i]=k++;
			}
			f=1;
		}
		else{
			for(int j=n-1;j>=0;j--){
				a[j][i]=k++;
			}
			f=0;
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cout<<a[i][j]<<" ";

		}
		cout<<endl;
	}





	return 0;
}