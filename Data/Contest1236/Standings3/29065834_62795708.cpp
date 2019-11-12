#include<bits/stdc++.h>
using namespace std;

int a[500][500];
int main(){
	int n;
	cin>>n;
	for(int i=0;i<n;i+=2){
		for(int j=0;j<n;j++){
			a[j][i]=i*n+j+1;
			a[n-j-1][i+1]=(i+1)*n+j+1;
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++)
			cout<<a[i][j]<<' ';
		cout<<'\n';
	}
	return 0;
}