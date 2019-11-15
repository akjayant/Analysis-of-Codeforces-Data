#include<bits/stdc++.h>
using namespace std;




int main(){
	
	int n,z=1,j,i;
	cin>>n;
	int arr[n][n];
	for(j=0;j<n;j++){
		for(i=0;i<n;i++){
			arr[i][j]=z++;
		}
		j++;
		if(j==n)break;
		for(i--;i>=0;i--){
			arr[i][j]=z++;
		}
	}
	for(i=0;i<n;i++)for(j=0;j<n;j++)cout<<arr[i][j]<<" \n"[j+1==n];
}