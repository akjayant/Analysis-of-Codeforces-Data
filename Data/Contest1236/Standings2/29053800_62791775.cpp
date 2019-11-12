#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false); cin.tie(0);
using namespace std;

int main(){
	IOS;
	int n;
	cin >> n;
	vector<vector<int>> num(n,vector<int>(n));
	int cnt=1;
	for(int i=0;i<n;i++){
		if(i&1){
			for(int j=0;j<n;j++){
				num[i][j]=cnt++;
			}
		}
		else{
			for(int j=n-1;j>=0;j--){
				num[i][j]=cnt++;
			}
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++) cout << num[j][i] << ' ';
		cout << '\n';
	}
	return 0;
}
