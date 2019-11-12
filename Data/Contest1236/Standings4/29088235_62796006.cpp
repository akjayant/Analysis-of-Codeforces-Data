#include<iostream>
using namespace std;
int a[303][303],n;
int main(){
	cin>>n;
	int f=1,g=1;
	for(int i=1;i<=n;++i){
		if(f==1){
			for(int j=1;j<=n;++j){
				a[i][j]=g++;
			}
		}
		else{
			for(int j=n;j;j--){
				a[i][j]=g++;
			}
		}
		f^=1;
	}
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j){
			cout<<a[j][i]<<(j==n?"":" ");
		}
		puts("");
	}
} 