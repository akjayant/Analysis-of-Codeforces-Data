#include<bits/stdc++.h>
using namespace std;
int a[305][305];
int main()
{
	int n;
	cin >> n;
	int cnt=0;
    for(int i=0;i<n;i+=2){
    	for(int j=0;j<n;j++){
    		a[j][i]=++cnt;
		}
		for(int j=n-1;j>=0;j--){
    		a[j][i+1]=++cnt;
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
    return 0;
}